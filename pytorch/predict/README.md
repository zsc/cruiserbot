# PyTorch on Raspberry Pi

## Usage
May need to set `export OMP_NUM_THREADS=2` to avoid segfaults.
```
python3 pred_video.py --pred --count 3000
```

## Install
### From wheels
1. Install torch from http://tomorrow.ai/shared/pytorch1.0_raspberry/torch-1.0.0a0%2B8322165-cp35-cp35m-linux_armv7l.whl .
1. `pip3 install pillow --user`
1. `pip3 install torchvision  --user --no-deps`

### From source
https://medium.com/hardware-interfacing/how-to-install-pytorch-v4-0-on-raspberry-pi-3b-odroids-and-other-arm-based-devices-91d62f2933c7

```
export NO_CUDA=1
export NO_DISTRIBUTED=1
export NO_MKLDNN=1 
export NO_NNPACK=1
export NO_QNNPACK=1
export NO_CAFFE2_OPS=1=1
```
