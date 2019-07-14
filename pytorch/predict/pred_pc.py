#!/usr/bin/env python3
import argparse
import os
import time
import numpy as np
import PIL
import torch
import torchvision
from torchvision import datasets, models, transforms

def get_loader():
    return transforms.Compose([
        transforms.Scale(256), transforms.CenterCrop(224),
        transforms.ToTensor(), 
        transforms.Normalize([0.485, 0.456, 0.406], [0.229, 0.224, 0.225])])

def get_model():
    #model = models.squeezenet1_0(pretrained=True)
    model = models.resnet18(pretrained=True)
    #model = model_ft.to(device)
    model.eval()
    return model

def image_loader(image_name, loader):
    """load image, returns cuda tensor"""
    image = PIL.Image.open(image_name)
    image = loader(image).float()
    image = image.unsqueeze(0)  #this is for VGG, may not be needed for ResNet
    return image

def show_model_outputs(outputs, top_k=1, lang='cn', idx2label_dic=[None]):
    if idx2label_dic[0] is None:
        if lang == 'cn':
            with open("imagenet1000_chinese.txt") as f:
                idx2label_dic[0] = {i:r.strip() for i, r in enumerate(f.readlines())}
        else:
            with open("imagenet1000_clsidx_to_labels.txt") as f:
                idx2label_dic[0] = eval(f.read())

    values = torch.topk(outputs, top_k)[0].data.numpy()[0]
    indices = torch.topk(outputs, top_k)[1].data.numpy()[0]
    ret = []
    for i in range(top_k):
        idx = indices[i]
        ret.append('{} {:.2f}'.format(idx2label_dic[0][idx], values[i]))
    return '\n'.join(ret)

if __name__ == '__main__':
    os.environ['OMP_NUM_THREADS'] = "2"
    parser = argparse.ArgumentParser()
    parser.add_argument('--lang', default='cn')
    parser.add_argument('--files', nargs='+', default=['cat.jpg', 'dog.jpg'])
    args = parser.parse_args()

    device = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")
    model = get_model()


    loader = get_loader()
    for fname in args.files:
        print('-'*30)
        print(fname)
        old = time.time()
        inputs = image_loader(fname, loader)
        inputs = inputs.to(device)
        print('load time: {:.1f}s'.format(time.time() - old))
        old = time.time()
        outputs = model(inputs)
        print('model time: {:.1f}s'.format(time.time() - old))
        print(show_model_outputs(outputs, top_k=5, lang=args.lang))

