import cv2

cap = cv2.VideoCapture('/dev/video1')
fourcc = cv2.VideoWriter_fourcc(*'XVID')
out = cv2.VideoWriter('output.avi',fourcc, 20.0, (640,480))
try:
    while True:
        ret, img = cap.read()
        print('#', end='', flush=True)
        out.write(img)
        #cv2.imshow('', img)
finally:
    out.release()
    cap.release()
