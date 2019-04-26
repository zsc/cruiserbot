from time import sleep
from picamera import PiCamera

with PiCamera(resolution=(1280, 720)) as camera:
    camera.start_preview()
    # Set ISO to the desired value
    camera.iso = 400
    # Wait for the automatic gain control to settle
    sleep(2)
    # Now fix the values
    camera.exposure_mode = 'off'
    g = camera.awb_gains
    camera.awb_mode = 'off'
    camera.awb_gains = g
    print(g)

    try:
        for i in range(7):
            #speed = camera.exposure_speed * 2 ** i
            #camera.shutter_speed = speed
            #print('speed {}'.format(speed))
            #camera.capture('/home/ubuntu/imgs/dark_s{}.jpg'.format(speed))
            iso = 100 * 2 ** i
            camera.iso = iso
            camera.capture('/home/ubuntu/imgs/dark_iso_{}.jpg'.format(iso))
            #sleep(1)
    finally:
        camera.stop_preview()
