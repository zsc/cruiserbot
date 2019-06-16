# main.py -- put your code here!
import pyb
import framebuf
fbuf = bytearray(160*128)
fb = framebuf.FrameBuffer(fbuf, 160, 128, framebuf.PL8)
tft = pyb.SCREEN()
fb.fill(8)
fb.text('Hello Micropython!', 10, 50, 2)
tft.show(fb, 1)
