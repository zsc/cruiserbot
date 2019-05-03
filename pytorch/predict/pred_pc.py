import time
import numpy as np
import PIL
import torch
import torchvision
from torchvision import datasets, models, transforms

def image_loader(image_name, loader):
    """load image, returns cuda tensor"""
    image = PIL.Image.open(image_name)
    image = loader(image).float()
    image = torch.autograd.Variable(image, requires_grad=False)
    image = image.unsqueeze(0)  #this is for VGG, may not be needed for ResNet
    return image

loader = transforms.Compose([
    transforms.Scale(256), transforms.CenterCrop(224),
    transforms.ToTensor(), 
    transforms.Normalize([0.485, 0.456, 0.406], [0.229, 0.224, 0.225])])

device = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")
model_ft = models.resnet18(pretrained=True)
num_ftrs = model_ft.fc.in_features

model = model_ft.to(device)
model.eval()

with open("imagenet1000_clsidx_to_labels.txt") as f:
    idx2label = eval(f.read())

for fname in ['cat.jpg', 'dog.jpg']:
    print('-'*30)
    print(fname)
    old = time.time()
    inputs = image_loader(fname, loader)
    inputs = inputs.to(device)
    print('load', time.time() - old)
    old = time.time()
    outputs = model(inputs)
    print('model', time.time() - old)
    for idx in torch.topk(outputs, 5)[1].data.numpy()[0]:
        print(idx2label[idx])
