#!/usr/bin/env python3
import cv2

cap = cv2.VideoCapture('/dev/video0')

try:
    while True:
        ret, img = cap.read()
        print('#', end='', flush=True)
        if img is not None:
            cv2.imshow('', img)
            cv2.waitKey(20)
finally:
    cap.release()
