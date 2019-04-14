#!/usr/bin/env python3
import serial
import time

if __name__ == '__main__':
  BAUDRATE = 115200
  ser = serial.Serial('/dev/tty.usbmodem1411', BAUDRATE)
  ser.baudrate = BAUDRATE
  cnt = 0
  while True:
    if cnt == 0:
        ser.write(b'A')
        print('A')
    else:
        ser.write(b'B')
        print('B')
    cnt = (cnt + 1) % 2
    ser.flush()
    print('here')
    #s = ser.read()
    #print('read: {}'.format(s))
    time.sleep(2)
