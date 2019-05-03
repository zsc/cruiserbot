import argparse
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

def image_loader(image_name, loader):
    """load image, returns cuda tensor"""
    image = PIL.Image.open(image_name)
    image = loader(image).float()
    image = torch.autograd.Variable(image, requires_grad=False)
    image = image.unsqueeze(0)  #this is for VGG, may not be needed for ResNet
    return image

def show_model_outputs(outputs, top_k=1):
    values = torch.topk(outputs, top_k)[0].data.numpy()[0]
    indices = torch.topk(outputs, top_k)[1].data.numpy()[0]
    for i in range(top_k):
        idx = indices[i]
        print('{} {:.2f}'.format(idx2label[idx], values[i]))

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--lang', default='cn')
    args = parser.parse_args()

    device = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")
    model_ft = models.resnet18(pretrained=True)
    model = model_ft.to(device)
    model.eval()

    if args.lang == 'cn':
        with open("imagenet1000_chinese.txt") as f:
            idx2label = {i:r.strip() for i, r in enumerate(f.readlines())}
    else:
        with open("imagenet1000_clsidx_to_labels.txt") as f:
            idx2label = eval(f.read())

    loader = get_loader()
    for fname in ['cat.jpg', 'dog.jpg']:
        print('-'*30)
        print(fname)
        old = time.time()
        inputs = image_loader(fname, loader)
        inputs = inputs.to(device)
        print('load time: {:.1f}s'.format(time.time() - old))
        old = time.time()
        outputs = model(inputs)
        print('model time: {:.1f}s'.format(time.time() - old))
        show_model_outputs(outputs, 5)

