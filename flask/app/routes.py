import random
import os
import cv2
import serial

from flask import make_response
from app import app

ser = None
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

@app.route('/can_recycle')
def can_recycle():
    proc_cmd('left')
    print('left, can recycle')
    return ""

@app.route('/cant_recycle')
def cant_recycle():
    proc_cmd('right')
    print('right, can recycle')
    return ""

@app.route('/clean')
def clean():
    proc_cmd('clean')
    print('clean')
    return ""
