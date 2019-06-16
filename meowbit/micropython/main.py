# main.py -- put your code here!
import pyb
import framebuf
fbuf = bytearray(160*128*2)
fb = framebuf.FrameBuffer(fbuf, 160, 128, framebuf.RGB565)
tft = pyb.SCREEN()
fb.fill(0)
#fb.text('Hello Micropython!', 10, 50, 2)
tft.show(fb)
fb.loadbmp('nut.bmp')
tft.show(fb)
