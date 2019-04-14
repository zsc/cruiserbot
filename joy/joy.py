#! /usr/bin/env python2
from __future__ import print_function
import rospy
from geometry_msgs.msg import Point
from sensor_msgs.msg import Joy
import serial
import time

# This ROS Node converts Joystick inputs from the joy node
# into commands for turtlesim or any other robot

# Receives joystick messages (subscribed to Joy topic)
# then converts the joysick inputs into Twist commands
# axis 1 aka left stick vertical controls linear speed
# axis 0 aka left stick horizonal controls angular speed

def callback(data, cnt=[0]):
    point = Point()
    point.x = data.axes[3]
    point.y = data.axes[4]
    print(point)
    cnt[0] = (cnt[0] + 1) % 200
    if cnt[0] == 0:
        if point.x > 0:
            ser.write(b'A')
            print('A')
        else:
            ser.write(b'B')
            print('B')
        ser.flush()
    #time.sleep(1)
    #pub.publish(point)

# Intializes everything
def start():
    BAUDRATE = 115200
    # publishing to "turtle1/cmd_vel" to control turtle1
    global ser
    ser = serial.Serial('/dev/ttyACM0', BAUDRATE)
    ser.baudrate = BAUDRATE
    #time.sleep(1)
    #ser.write(b'A')

    global pub
    #pub = rospy.Publisher('turtle1/cmd_vel', Point)
    # subscribed to joystick inputs on topic "joy"
    rospy.Subscriber("joy", Joy, callback)
    # starts the node
    rospy.init_node('Joy2Turtle')
    rospy.spin()

if __name__ == '__main__':
    start()
