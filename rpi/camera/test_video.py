# import the necessary packages
import numpy as np
from picamera.array import PiRGBArray
from picamera import PiCamera
import time
#import cv2
 
# initialize the camera and grab a reference to the raw camera capture
camera = PiCamera()
camera.resolution = (640, 480)
camera.framerate = 32
rawCapture = PiRGBArray(camera, size=(640, 480))
 
# allow the camera to warmup
time.sleep(0.1)
 
# capture frames from the camera
cnt = 0
for frame in camera.capture_continuous(rawCapture, format="bgr", use_video_port=True):
    # grab the raw NumPy array representing the image, then initialize the timestamp
    # and occupied/unoccupied text
    image = frame.array
 
    # show the frame
    print(image.sum(), 'image.sum', image.shape, 'image.shape')
    np.save('image{:03d}.npy'.format(cnt), image)
    #cv2.imshow("Frame", image)
    #key = cv2.waitKey(1) & 0xFF
 
    # clear the stream in preparation for the next frame
    rawCapture.truncate(0)
 
    cnt += 1
    if cnt == 30:
        break
    # if the `q` key was pressed, break from the loop
    #if key == ord("q"):
     #   break
