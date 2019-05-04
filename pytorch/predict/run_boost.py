#!/usr/bin/env python3
import copy
import argparse
import time
import os
import numpy as np
from picamera.array import PiRGBArray
from picamera import PiCamera
import PIL
import torch
import torchvision
from torchvision import models, transforms

from pylgbst import *
from pylgbst.comms import DebugServerConnection
from pylgbst.movehub import MoveHub, COLORS, COLOR_BLACK
from pylgbst.peripherals import EncodedMotor, TiltSensor, Amperage, Voltage

log = logging.getLogger("demo")

from pred_pc import get_loader, get_model, show_model_outputs

def get_camera():
    camera = PiCamera()
    camera.resolution = (640, 480)
    camera.framerate = 5
    return camera

def pred_image(model, image, loader):
    image = loader(image).float()
    image = image.unsqueeze(0)
    return model(image)

def main_loop(camera, hub, model, args):
    loader = get_loader()
    rawCapture = PiRGBArray(camera, size=(640, 480))
    cnt = 0
    for frame in camera.capture_continuous(rawCapture, format="bgr", use_video_port=False):
        print('count {}'.format(cnt))
        image = frame.array
     
        print(image.sum(), 'image.sum', image.shape, 'image.shape')
        if args.save_frame:
            np.save('image{:03d}.npy'.format(cnt), image)

        if args.pred:
            outputs = pred_image(model, PIL.Image.fromarray(image, 'RGB'), loader)
            pred_str = show_model_outputs(outputs, top_k=3)
            print(pred_str)
     
        # clear the stream in preparation for the next frame
        rawCapture.truncate(0)
     
        cnt += 1
        if cnt == args.count:
            break

if __name__ == '__main__':
    logging.basicConfig(level=logging.INFO)
    os.environ['OMP_NUM_THREADS'] = "2"
    parser = argparse.ArgumentParser()
    parser.add_argument('--save_frame', action='store_true')
    parser.add_argument('--pred', action='store_true')
    parser.add_argument('--count', type=int, default=30)
    args = parser.parse_args()

    camera = get_camera()
    device = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")
    model = get_model()
    
    '''
    try:
        connection = DebugServerConnection()
    except BaseException:
        logging.debug("Failed to use debug server: %s", traceback.format_exc())
    '''
    connection = get_connection_auto()

    try:
        hub = MoveHub(connection)
        time.sleep(1)
        main_loop(camera, hub, model, args)
    finally:
        connection.disconnect()

