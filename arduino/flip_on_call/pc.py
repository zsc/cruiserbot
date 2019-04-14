#!/usr/bin/env python3
import serial
import time

if __name__ == '__main__':
  BAUDRATE = 9600
  ser = serial.Serial('/dev/tty.usbmodem1421', BAUDRATE)
  ser.baudrate = BAUDRATE
  while True:
    ser.write(b'A')
    ser.flush()
    print('here')
    s = ser.read()
    print(s)
    time.sleep(3)
