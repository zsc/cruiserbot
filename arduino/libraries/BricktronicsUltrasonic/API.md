# BricktronicsUltrasonic API

This library interfaces with LEGO NXT ultrasonic sensors. It can be used with the [Bricktronics Shield](https://store.wayneandlayne.com/products/bricktronics-shield-kit.html), [Bricktronics Megashield](https://store.wayneandlayne.com/products/bricktronics-megashield-kit.html), or standalone with the [Bricktronics Breakout Board](https://store.wayneandlayne.com/products/bricktronics-breakout-board.html). For the shield/megashield, use the constructor below with the `BricktronicsSensorSettings` struct, otherwise use the constructor below that accepts the pin numbers.

# Connection with [Bricktronics Shield](https://store.wayneandlayne.com/products/bricktronics-shield-kit.html)

Use the ultrasonic sensor with sensor port 3 or 4 on the Bricktronics Shield. Use the jumpers to connect pins 1-2 and 4-5.

Constructor usage for Bricktronics Shield
```C++
#include <Wire.h>
#include <Adafruit_MCP23017.h>
#include <BricktronicsShield.h>
#include <BricktronicsUltrasonic.h>
BricktronicsUltrasonic u(BricktronicsShield::SENSOR_3);
```

# Connection with [Bricktronics Megashield](https://store.wayneandlayne.com/products/bricktronics-megashield-kit.html)

Use the ultrasonic sensor with any sensor port on the Bricktronics Megashield. Use the jumpers to connect pins 1-2 and 4-5.

Constructor usage for Bricktronics Megashield
```C++
#include <BricktronicsMegashield.h>
#include <BricktronicsUltrasonic.h>
BricktronicsUltrasonic u(BricktronicsMegashield::SENSOR_1);
```

# Connection with [Bricktronics Breakout Board](https://store.wayneandlayne.com/products/bricktronics-breakout-board.html)

* Pin 1 - Connect to an external power supply between 7.2 and 9 volts DC
* Pin 2 - Connect to Ground
* Pin 3 - Connect to Ground
* Pin 4 - Connect to 5V
* Pin 5 - Connect to any digital pin (this is `sclPin` below)
* Pin 6 - Connect to any digital pin (this is `sdaPin` below)

Constructor usage for Bricktronics Breakout Board:
```C++
#include <BricktronicsUltrasonic.h>
BricktronicsUltrasonic u(8, 12); // Constructor arguments: sclPin, sdaPin
```

# Quick Example

```C++
#include <BricktronicsUltrasonic.h>

// Use one of the constructor options listed above.
BricktronicsUltrasonic u(8, 12);

void setup()
{
    Serial.begin(115200);
    // If using a Bricktronics Shield, you need to call
    // BricktronicsShield::begin();
    u.begin();
}

void loop()
{
    Serial.println(u.getDistance());
    delay(100);
}
```

# Constructors and `begin()`

#### `BricktronicsUltrasonic(uint8_t sclPin, uint8_t sdaPin)`

Constructor - Simple constructor that accepts the SCL and SDA pin numbers.

**Parameters**

* `uint8_t sclPin` - The Arduino pin number where the sensor's pin 5 is connected. Digital input and output.
* `uint8_t sdaPin` - The Arduino pin number where the sensor's pin 6 is connected. Digital input and output.


#### `BricktronicsUltrasonic(const BricktronicsSensorSettings &settings)`

Constructor - Advanced constructor that accepts a SensorSettings struct to also override the low-level Arduino functions.

**Parameters**

* `const BricktronicsSensorSettings &settings` - A const reference to the struct containing all the sensor settings. Get these structs from the [BricktronicsShield](https://github.com/wayneandlayne/BricktronicsShield) or [BricktronicsMegashield](https://github.com/wayneandlayne/BricktronicsMegashield) library.

#### `void begin(void)`

Call this function once for each instance during your setup() function.


# Basic ultrasonic sensor functions

#### `uint8_t getDistance(void)`

Basic ultrasonic sensor read function. Returns the latest sensor reading, returns 0 in case of error. Measured distance is in units of centimeters.

