#!/usr/bin/env python3
import argparse
import os
import time
import numpy as np
import PIL
import cv2
import torch
import torchvision
from torchvision import datasets, models, transforms

class ImagePred:
    def __init__(self, lang='cn'):
        self.loader = self.get_loader()
        self.device = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")
        self.model = self.get_model()

        if lang == 'cn':
            with open("imagenet1000_chinese.txt") as f:
                self.idx2label_dic = {i:r.strip() for i, r in enumerate(f.readlines())}
        else:
            with open("imagenet1000_clsidx_to_labels.txt") as f:
                self.idx2label_dic = eval(f.read())

    def get_loader(self):
        return transforms.Compose([
            transforms.Scale(256), transforms.CenterCrop(224),
            transforms.ToTensor(), 
            transforms.Normalize([0.485, 0.456, 0.406], [0.229, 0.224, 0.225])])

    def get_model(self):
        #model = models.squeezenet1_0(pretrained=True)
        model = models.resnet18(pretrained=True)
        model.cuda()
        #model = model.to(self.device)
        model.eval()
        return model

    def image_loader(self, img):
        """load image, returns cuda tensor"""
        img = img[:,:,::-1]
        image = PIL.Image.fromarray(img)
        #image = PIL.Image.open(image_name)
        image = self.loader(image).float()
        image = image.unsqueeze(0)  #this is for VGG, may not be needed for ResNet
        image = image.to(self.device)
        return image

    def pred(self, img):
        image = self.image_loader(img)
        return self.model(image)

    def show_model_outputs(self, outputs, top_k=1, lang='cn'):
        values = torch.topk(outputs, top_k)[0].data.numpy()[0]
        indices = torch.topk(outputs, top_k)[1].data.numpy()[0]
        ret = []
        for i in range(top_k):
            idx = indices[i]
            ret.append('{} {:.2f}'.format(self.idx2label_dic[idx], values[i]))
        return '\n'.join(ret)

if __name__ == '__main__':
    os.environ['OMP_NUM_THREADS'] = "2"
    parser = argparse.ArgumentParser()
    parser.add_argument('--lang', default='cn')
    parser.add_argument('--files', nargs='+', default=['cat.jpg', 'dog.jpg'])
    args = parser.parse_args()

    image_pred = ImagePred()
    for fname in args.files:
        print('-'*30)
        print(fname)
        old = time.time()
        img = cv2.imread(fname)
        print('load time: {:.1f}s'.format(time.time() - old))
        old = time.time()
        outputs = image_pred.pred(img)
        print('model time: {:.1f}s'.format(time.time() - old))
        print(image_pred.show_model_outputs(outputs.cpu(), top_k=5, lang=args.lang))

