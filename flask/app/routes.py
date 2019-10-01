import random
import os
import cv2

from flask import make_response
from app import app

cap = None

@app.route('/')
@app.route('/index')
def index():
    global cap
    if cap is None:
        dev = '/dev/video0'
        if not os.path.exists(dev):
            dev = 0
        cap = cv2.VideoCapture(dev)

    try:
        ret, img = cap.read()
        img = cv2.resize(img, (0, 0), fx=0.25, fy=0.25)
        _, img_encoded = cv2.imencode('.jpg', img)
        response = make_response(img_encoded.tostring())
        response.headers.set('Content-Type', 'image/jpeg')
        return response
    except Exception as e:
        print(e)
        return "Hi there {}!".format(random.randint(0, 10))

@app.route('/can_recycle')
def can_recycle():
    print('can recycle')
    return ""

@app.route('/cant_recycle')
def cant_recycle():
    print('can recycle')
    return ""

@app.route('/clean')
def clean():
    print('clean')
    return ""
