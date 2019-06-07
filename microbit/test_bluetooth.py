#!/usr/bin/env python3

from bluezero import microbit
ubit = microbit.Microbit(adapter_addr='43:43:A1:12:1F:AC',
                         device_addr='D8:8E:DA:20:E3:D5',
                         accelerometer_service=True,
                         button_service=True,
                         led_service=True,
                         magnetometer_service=False,
                         pin_service=False,
                         temperature_service=True)
my_text = 'Hello, world'
ubit.connect()

while my_text is not '':
    ubit.text = my_text
    my_text = input('Enter message: ')

ubit.disconnect()
