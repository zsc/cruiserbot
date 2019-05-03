import time
import numpy as np
from picamera.array import PiRGBArray
from picamera import PiCamera
 
# initialize the camera and grab a reference to the raw camera capture
camera = PiCamera()
rawCapture = PiRGBArray(camera)
 
# allow the camera to warmup
time.sleep(3)
 
# grab an image from the camera
camera.capture(rawCapture, format="bgr")
image = rawCapture.array
 
np.save('image.npy', image)
# display the image on screen and wait for a keypress
#import cv2
#cv2.imwrite("test.jpg", image)
#cv2.waitKey(0)
