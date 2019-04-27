```
raspivid -o - -n -fps 15 -w 1280 -h 720 -t 0 |cvlc -vvv stream:///dev/stdin --sout '#rtp{sdp=rtsp://:8554/}' :demux=h264 :h264-fps=15
```

In a laptop, run VLC and open media "rtsp://raspberry-pi-ip:8554/" . Note the final slash **cannot** be omitted.
