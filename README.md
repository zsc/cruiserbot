# cruiserbot

## Setup
### RPI
In \*shrc
```
export ROS_HOSTNAME=<Raspberry-Pi-IP>
export ROS_MASTER_URI=http://$ROS_HOSTNAME:11311
```

### PC
In \*shrc
```
```

## Run
### Camera node
`roslaunch raspicam_node camerav1_1280x720.launch`

### Process image on PC
`python2 image_proc.py`
