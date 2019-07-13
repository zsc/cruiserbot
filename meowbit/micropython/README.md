Turns out we can connect to micropython REPL on meowbit directly:
```
screen /dev/cu.usbmodem1412 115200
```

https://support.microbit.org/support/solutions/articles/19000022103-outputing-serial-data-from-the-micro-bit-to-a-computer


```
>>> import uos;print(uos.uname())
(sysname='pyboard', nodename='pyboard', release='1.9.4', version='v1.9.4-622-g06ff7fabf-dirty on 2019-05-27', machine='MEOWBIT with STM32F401xE')
```
