# cruiserbot


## PyTorch on Raspberry Pi
https://medium.com/hardware-interfacing/how-to-install-pytorch-v4-0-on-raspberry-pi-3b-odroids-and-other-arm-based-devices-91d62f2933c7

## Tensorflow on Raspberry Pi
1. Follow instructions here to install tensorflow: https://github.com/phopley/rodney-project/wiki/Raspberry-Pi-image#3-install-tensorflow .
1. Get resnet_v2_50 from https://github.com/tensorflow/models/tree/master/research/slim#pre-trained-models .
1. Use code here to test the installed TF: https://github.com/zsc/tf-tutorials/tree/master/02-feature-inversion

## Processing Video stream from Raspberry Pi on PC via ROS
### Setup
#### RPI
In \*shrc
```
export ROS_HOSTNAME=<Raspberry-Pi-IP>
export ROS_MASTER_URI=http://$ROS_HOSTNAME:11311
```

#### PC
In \*shrc
```
export ROS_HOSTNAME=<PC-IP>
export ROS_MASTER_URI=http://<Raspberry-Pi-IP>:11311
```

### Run
#### Camera node
`roslaunch raspicam_node camerav1_1280x720.launch`

#### Process image on PC
`python2 image_proc.py`
