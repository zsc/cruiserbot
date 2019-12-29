import random
import os
import cv2
import serial
import glob
import numpy as np
try:
   import cPickle as pickle
except:
   import pickle

from sklearn import neighbors, datasets
from flask import make_response, render_template, Response
from app import app
from .pred_pc import ImagePred

ser = None
cap = None
image_pred = ImagePred()
get_words = lambda:['empty', 'nuts', 'pencil', 'tissue', 'plastic']

def load_dir(path='crops', test_ratio=0.3):
    xs = []; ys = []; test_xs = []; test_ys = []
    for label, tag in enumerate(get_words()):
        for fname in glob.glob('{}/{}/*.png'.format(path, tag)):
            img = cv2.imread(fname)
            outputs = image_pred.pred(img)
            #print(outputs.cpu().shape);break
            feature = outputs.cpu().detach().numpy()[0]
            if test_ratio > np.random.rand(1)[0]:
                test_xs.append(feature); test_ys.append(label)
            else:
                xs.append(feature); ys.append(label)
    return {'xs':xs, 'ys':ys, 'test_xs':test_xs, 'test_ys':test_ys}

def build_classifier(n_neighbors=3):
    pickle_name = 'class.pkl'
    if os.path.exists(pickle_name):
        with open(pickle_name, 'rb') as f:
            return pickle.load(f)
    res = load_dir(test_ratio=0)
    xs, ys = res['xs'], res['ys']
    clf = neighbors.KNeighborsClassifier(n_neighbors, weights='distance')
    clf.fit(xs, ys)
    with open(pickle_name, 'wb') as f:
        pickle.dump(clf, f)
    return clf

classifier = build_classifier()
g_image = None
g_pred_word = 'empty'

def refresh_pred(cnt=[0]):
    global g_image
    if g_image is None:
        frame = np.zeros((40, 40, 3)).astype('uint8')
    else:
        frame = g_image
    cnt[0] += 1
    cv2.imwrite('{:03d}.png'.format(cnt[0]), frame)
    out = image_pred.pred(frame).cpu()
    pred_res = classifier.predict(out.detach().numpy())[0]
    global g_pred_word
    g_pred_word = get_words()[pred_res]
    #pred_res = image_pred.show_model_outputs(out, top_k=2, short=True)
    print(g_pred_word)
    return render_template('index.html', title='{}'.format(g_pred_word))

@app.route('/')
@app.route('/index')
def index():
    return refresh_pred()

def gen():
    while True:
        frame = get_frame()
        global g_image
        g_image = frame
        _, img_encoded = cv2.imencode('.jpg', frame)
        yield (b'--frame\r\n'
               b'Content-Type: image/jpeg\r\n\r\n' + img_encoded.tostring() + b'\r\n')

@app.route('/video_feed')
def video_feed():
    return Response(gen(),
                    mimetype='multipart/x-mixed-replace; boundary=frame')

def get_frame():
    global cap
    if cap is None:
        dev = '/dev/video0'
        if not os.path.exists(dev):
            dev = 0
        cap = cv2.VideoCapture(dev)

    try:
        ret, img = cap.read()
        scale = 300 
        y0 = (img.shape[0] - scale)//2
        x0 = (img.shape[1] - scale)//2
        img = img[y0:y0+scale, x0:x0+scale]
        #img = cv2.resize(img, (0, 0), fx=0.4, fy=0.4)
    except Exception as e:
        print(e)
        img = np.zeros((40, 40, 3)).astype('uint8')
    return cv2.resize(img, (224, 224))

def proc_cmd(cmd):
    global ser
    if ser is None:
        ser = serial.Serial('/dev/ttyACM0', 115200)
    try:
        ser_write = {'left':2, 'right':1, 'clean':3}[cmd]
        if ser_write == 3:
            ser.write(b'3\x0a\x0d')
        elif ser_write == 2:
            ser.write(b'2\x0a\x0d')
        else:
            ser.write(b'1\x0a\x0d')
    except Exception as e:
        print(e)

@app.route('/can_recycle')
def can_recycle():
    proc_cmd('left')
    print('left, can recycle')
    return refresh_pred()

@app.route('/cant_recycle')
def cant_recycle():
    proc_cmd('right')
    print('right, can recycle')
    return refresh_pred()

@app.route('/clean')
def clean():
    proc_cmd('clean')
    print('clean')
    return refresh_pred()

@app.route('/auto')
def set_auto_mode():
    proc_cmd('auto')
    print('auto mode')
    return ""

@app.route('/manual')
def set_manual_mode():
    proc_cmd('manual')
    print('manual mode')
    return ""

@app.route('/reboot')
def reboot():
    print('reboot')
    os.system('yes ubuntu|sudo reboot')
    return ""

