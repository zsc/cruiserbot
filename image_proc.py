#!/usr/bin/env python2
from __future__ import print_function
import argparse
"""OpenCV feature detectors with ros CompressedImage Topics in python.

This example subscribes to a ros topic containing sensor_msgs 
CompressedImage. It converts the CompressedImage into a numpy.ndarray, 
then detects and marks features in that image. It finally displays 
and publishes the new image - again as CompressedImage topic.
"""
__author__ =  'Simon Haller <simon.haller at uibk.ac.at>'
__version__=  '0.1'
__license__ = 'BSD'
# Python libs
import sys, time

# numpy and scipy
import numpy as np
from scipy.ndimage import filters

# OpenCV
import cv2

# Ros libraries
import roslib
import rospy

# Ros Messages
from sensor_msgs.msg import CompressedImage
# We do not use cv_bridge it does not support CompressedImage in python
# from cv_bridge import CvBridge, CvBridgeError

class image_feature:

    def __init__(self, opts):
        '''Initialize ros publisher, ros subscriber'''
        self.opts = opts
        # topic where we publish
        self.image_pub = rospy.Publisher("/output/image_raw/compressed",
            CompressedImage)
        # self.bridge = CvBridge()

        # subscribed Topic
        self.subscriber = rospy.Subscriber("/raspicam_node/image/compressed",
            CompressedImage, self.callback,  queue_size = 1)
        if self.opts.verbose :
            print("subscribed to /raspicam_node/image/compressed")
        if self.opts.save_video:
            fourcc = cv2.VideoWriter_fourcc(*"XVID")
            self.vid = cv2.VideoWriter('output.avi', fourcc, 5, (1280, 720), True)


    def callback(self, ros_data):
        '''Callback function of subscribed topic. 
        Here images get converted and features detected'''
        if self.opts.verbose :
            print('received image of type: "%s"' % ros_data.format)

        #### direct conversion to CV2 ####
        np_arr = np.fromstring(ros_data.data, np.uint8)
        image_np = cv2.imdecode(np_arr, 1)
        
        #### Feature detectors using CV2 #### 
        # "","Grid","Pyramid" + 
        # "FAST","GFTT","HARRIS","MSER","ORB","SIFT","STAR","SURF"
        #method = "GridFAST"
        #feat_det = cv2.FeatureDetector_create(method)
        #time1 = time.time()

        # convert np image to grayscale
        #featPoints = feat_det.detect(
        #    cv2.cvtColor(image_np, cv2.COLOR_BGR2GRAY))
        #time2 = time.time()
        #if self.opts.verbose :
        #    print '%s detector found: %s points in: %s sec.'%(method,
        #        len(featPoints),time2-time1)

        #for featpoint in featPoints:
        #    x,y = featpoint.pt
        #    cv2.circle(image_np,(int(x),int(y)), 3, (0,0,255), -1)
        
        cv2.imshow('cv_img', image_np)
        cv2.waitKey(2)

        if self.opts.save_video:
            self.vid.write(image_np)

        #### Create CompressedIamge ####
        msg = CompressedImage()
        msg.header.stamp = rospy.Time.now()
        msg.format = "jpeg"
        msg.data = np.array(cv2.imencode('.jpg', image_np)[1]).tostring()
        # Publish new image
        self.image_pub.publish(msg)
        
        #self.subscriber.unregister()

def main(args):
    '''Initializes and cleanup ros node'''
    ic = image_feature(args)
    rospy.init_node('image_feature', anonymous=True)
    try:
        rospy.spin()
    except KeyboardInterrupt:
        ic.vid.release()
        print("Shutting down ROS Image feature detector module")
    cv2.destroyAllWindows()

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--verbose', action='store_true')
    parser.add_argument('--save_video', action='store_true')
    args = parser.parse_args()
    main(args)
