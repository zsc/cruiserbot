'''
for i in `seq 1 10`;do echo $i;ssh rpi2 'raspistill --raw -o out.jpg';scp rpi2:out.jpg out$i.jpg;sleep 1;done
'''

import glob
from picamraw import PiRawBayer, PiCameraVersion
import numpy as np

jpgs = sorted(glob.glob('out*.jpg'))
imgs = []
print(jpgs)

for jpg in jpgs:
    raw_bayer = PiRawBayer(
        filepath=jpg,  # A JPEG+RAW file, e.g. an image captured using raspistill with the "--raw" flag
        camera_version=PiCameraVersion.V1,
        sensor_mode=0
    )
    imgs.append(raw_bayer.to_rgb())
cv2.imwrite('/tmp/t.png', (np.mean(imgs, axis=0)[:,:,::-1] * 5).astype('uint8'))
