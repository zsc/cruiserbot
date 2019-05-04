import copy
import gc
import argparse
import time
import numpy as np
from picamera.array import PiRGBArray
from picamera import PiCamera
#import cv2
import PIL
import torch
import torchvision
from torchvision import models, transforms

from pred_pc import get_loader, get_model, show_model_outputs

def get_camera():
    camera = PiCamera()
    camera.resolution = (640, 480)
    camera.framerate = 5
    return camera

def pred_image(model, image, loader):
    image = loader(image).float()
    image = torch.autograd.Variable(image, requires_grad=False)
    image = image.unsqueeze(0)
    return model(image)

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--save_frame', action='store_true')
    parser.add_argument('--pred', action='store_true')
    parser.add_argument('--count', type=int, default=30)
    args = parser.parse_args()

    camera = get_camera()
    rawCapture = PiRGBArray(camera, size=(640, 480))
    device = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")
    model = get_model()
    loader = get_loader()
     
    time.sleep(1)
    cnt = 0

    with open('preds.txt', 'w') as preds_f:
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
                #preds_f.write('{}\n'.format(cnt))
                #preds_f.write(pred_str + '\n')
                #gc.collect()
            #cv2.imshow("Frame", image)
            #key = cv2.waitKey(1) & 0xFF
         
            # clear the stream in preparation for the next frame
            rawCapture.truncate(0)
         
            cnt += 1
            if cnt == args.count:
                break
