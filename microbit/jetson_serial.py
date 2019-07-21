import serial
import time

ser = serial.Serial('/dev/ttyACM0', 115200)
for i in range(10):
  ser.write(b'1\x0a\x0d')
  time.sleep(1)
ser.close()
