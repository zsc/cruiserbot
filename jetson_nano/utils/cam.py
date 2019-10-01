#!/usr/bin/env python3
import numpy as np
import cv2
import serial

ser = serial.Serial('/dev/ttyACM0', 115200)
cap = cv2.VideoCapture('/dev/video0')

try:
    while True:
        ret, img = cap.read()
        #print('#', end='', flush=True)
        if img is not None:
            avg = img.mean(axis=1).mean(axis=0)
            if avg[0] > 1.3 * avg[2]:
                ser.write(b'2\x0a\x0d')
                ser_write = 2
            elif 1.3 * avg[0] < avg[2]:
                ser.write(b'1\x0a\x0d')
                ser_write = 1
            else:
                ser.write(b'0\x0a\x0d')
                ser_write = 0
            print('avg: {}, ser: {}'.format(avg, ser_write))
            #ser.write(b'\x0a\x0d')
            cv2.imshow('', img)
            cv2.waitKey(10)
finally:
    cap.release()
