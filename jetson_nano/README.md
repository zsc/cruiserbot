## Model downloads
https://github.com/dusty-nv/jetson-inference/releases

## GPIO
https://devtalk.nvidia.com/default/topic/1054876/jetson-nano/i-want-to-control-the-pin-of-the-bcm-code-i-want-to-know-which-gpiochip-is-under-sys-class-gpio-/
https://www.securipi.co.uk/jetson.pdf

We can just use Board Pin by `GPIO.setmode(GPIO.BOARD)`.

`jetson-gpio\lib\python\Jetson\GPIO`

Each row interpreted as in:
```
(16, "/sys/devices/6000d000.gpio", 19, 10, 'SPI0_MOSI', 'SPI0_MOSI'),
BCM = 10
BOARD PIN =19
```


```
JETSON_NANO_PIN_DEFS = [
    (216, "/sys/devices/6000d000.gpio", 7, 4, 'GPIO9', 'GPIO9'),
    (50, "/sys/devices/6000d000.gpio", 11, 17, 'UART1_RTS', 'UART1_RTS'),
    (79, "/sys/devices/6000d000.gpio", 12, 18, 'I2S0_SCLK', 'I2S0_SCLK'),
    (14, "/sys/devices/6000d000.gpio", 13, 27, 'SPI1_SCK', 'SPI1_SCK'),
    (194, "/sys/devices/6000d000.gpio", 15, 22, 'GPIO12', 'GPIO12'),
    (232, "/sys/devices/6000d000.gpio", 16, 23, 'SPI1_CS1', 'SPI1_CS1'),
    (15, "/sys/devices/6000d000.gpio", 18, 24, 'SPI1_CS0', 'SPI1_CS0'),
    (16, "/sys/devices/6000d000.gpio", 19, 10, 'SPI0_MOSI', 'SPI0_MOSI'),
    (17, "/sys/devices/6000d000.gpio", 21, 9, 'SPI0_MISO', 'SPI0_MISO'),
    (13, "/sys/devices/6000d000.gpio", 22, 25, 'SPI1_MISO', 'SPI1_MISO'),
    (18, "/sys/devices/6000d000.gpio", 23, 11, 'SPI0_SCK', 'SPI0_SCK'),
    (19, "/sys/devices/6000d000.gpio", 24, 8, 'SPI0_CS0', 'SPI0_CS0'),
    (20, "/sys/devices/6000d000.gpio", 26, 7, 'SPI0_CS1', 'SPI0_CS1'),
    (149, "/sys/devices/6000d000.gpio", 29, 5, 'GPIO01', 'GPIO01'),
    (200, "/sys/devices/6000d000.gpio", 31, 6, 'GPIO11', 'GPIO11'),
    (168, "/sys/devices/6000d000.gpio", 32, 12, 'GPIO07', 'GPIO07'),
    (38, "/sys/devices/6000d000.gpio", 33, 13, 'GPIO13', 'GPIO13'),
    (76, "/sys/devices/6000d000.gpio", 35, 19, 'I2S0_FS', 'I2S0_FS'),
    (51, "/sys/devices/6000d000.gpio", 36, 16, 'UART1_CTS', 'UART1_CTS'),
    (12, "/sys/devices/6000d000.gpio", 37, 26, 'SPI1_MOSI', 'SPI1_MOSI'),
    (77, "/sys/devices/6000d000.gpio", 38, 20, 'I2S0_DIN', 'I2S0_DIN'),
    (78, "/sys/devices/6000d000.gpio", 40, 21, 'I2S0_DOUT', 'I2S0_DOUT')
```
