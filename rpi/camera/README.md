## raspivid
```
raspivid -o - -n -fps 15 -w 1280 -h 720 -t 0 |cvlc -vvv stream:///dev/stdin --sout '#rtp{sdp=rtsp://:8554/}' :demux=h264 :h264-fps=15
```

From http://c.wensheng.org/2017/05/18/stream-from-raspberrypi/ .

In a laptop, run VLC and open media "rtsp://raspberry-pi-ip:8554/" . Note the final slash **cannot** be omitted.

## picamera
https://www.pyimagesearch.com/2015/03/30/accessing-the-raspberry-pi-camera-with-opencv-and-python/
