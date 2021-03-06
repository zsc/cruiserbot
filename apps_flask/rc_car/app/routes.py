import random
import os
import cv2
import serial

from flask import make_response, render_template, Response
from app import app

ser = None
cap = None

@app.route('/')
@app.route('/index')
def index():
    frame = get_frame()
    #out = image_pred.pred(cv2.resize(frame, (224, 224))).cpu()
    pred_res = 'Video' #image_pred.show_model_outputs(out, top_k=2, short=True)
    #print(pred_res)
    return render_template('index.html', title=pred_res)

def gen():
    while True:
        frame = get_frame()
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
        img = np.zeros(40, 40).astype('uint8')
    return img

def proc_cmd(cmd):
    ser_write = {'left':2, 'right':1, 'clean':3}[cmd]

    global ser
    if ser is None:
        ser = serial.Serial('/dev/ttyACM0', 115200)
    try:
        if ser_write == 3:
            ser.write(b'3\x0a\x0d')
        elif ser_write == 2:
            ser.write(b'2\x0a\x0d')
        else:
            ser.write(b'1\x0a\x0d')
    except Exception as e:
        print(e)

@app.route('/left')
def can_recycle():
    proc_cmd('left')
    print('left')
    return ""

@app.route('/right')
def cant_recycle():
    proc_cmd('right')
    print('right')
    return ""

@app.route('/clean')
def clean():
    proc_cmd('clean')
    print('clean')
    return ""
