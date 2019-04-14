# BricktronicsColor API

This library interfaces with LEGO NXT color sensors. It can be used with the [Bricktronics Shield](https://store.wayneandlayne.com/products/bricktronics-shield-kit.html), [Bricktronics Megashield](https://store.wayneandlayne.com/products/bricktronics-megashield-kit.html), or standalone with the [Bricktronics Breakout Board](https://store.wayneandlayne.com/products/bricktronics-breakout-board.html). For the shield/megashield, use the constructor below with the `BricktronicsSensorSettings` struct, otherwise use the constructor below that accepts the input pin numbers.

# Connection with [Bricktronics Shield](https://store.wayneandlayne.com/products/bricktronics-shield-kit.html)

Use the color sensor with sensor port 3 or 4 on the Bricktronics Shield. Use the jumpers to connect pins 3-4.

Constructor usage for Bricktronics Shield
```C++
#include <Wire.h>
#include <Adafruit_MCP23017.h>
#include <BricktronicsShield.h>
#include <BricktronicsColor.h>
BricktronicsColor c(BricktronicsShield::SENSOR_3);
```

# Connection with [Bricktronics Megashield](https://store.wayneandlayne.com/products/bricktronics-megashield-kit.html)

Use the color sensor with any sensor port on the Bricktronics Megashield. Use the jumpers to connect pins 3-4.

Constructor usage for Bricktronics Megashield
```C++
#include <BricktronicsMegashield.h>
#include <BricktronicsColor.h>
BricktronicsColor c(BricktronicsMegashield::SENSOR_1);
```

# Connection with [Bricktronics Breakout Board](https://store.wayneandlayne.com/products/bricktronics-breakout-board.html)

* Pin 1 - Unused
* Pin 2 - Connect to Ground
* Pin 3 - Connect to Ground
* Pin 4 - Connect to 5V
* Pin 5 - Connect to any digital pin (this is clockPin)
* Pin 6 - Connect to any analog input pin (this is dataPin)

Constructor usage for Bricktronics Breakout Board:
```C++
#include <BricktronicsColor.h>
BricktronicsColor c(8, 16); // Constructor arguments: clockPin, dataPin
```

# Quick Example

```C++
#include <BricktronicsColor.h>

// Use one of the constructor options listed above.
BricktronicsColor c(8, 16);

void setup()
{
    Serial.begin(115200);
    // If using a Bricktronics Shield, you need to call
    // BricktronicsShield::begin();
    c.begin();
}

void loop()
{
    c.printColor(c.getColor());
    delay(100);
}
```

# Constructors and `begin()`

#### `BricktronicsColor(uint8_t clockPin, uint8_t dataPin)`

Constructor - Simple constructor that accepts the clock and data pins

**Parameters**

* `uint8_t clockPin` - The Arduino pin number where the sensor's pin 5 is connected.
* `uint8_t dataPin` - The Arduino pin number where the sensor's pin 6 is connected. Must have analog input.


#### `BricktronicsColor(const BricktronicsSensorSettings &settings)`

Constructor - Advanced constructor that accepts a SensorSettings struct to also override the low-level Arduino functions.

**Parameters**

* `const BricktronicsSensorSettings &settings` - A const reference to the struct containing all the sensor settings. Get these structs from the [BricktronicsShield](https://github.com/wayneandlayne/BricktronicsShield) or [BricktronicsMegashield](https://github.com/wayneandlayne/BricktronicsMegashield) library.

#### `void begin(void)`

Set up the sensor library internals and pin modes. Defaults to full-color mode. Call this function once for each instance during your setup() function.


#### `void begin(uint8_t modeType)`

Set up the sensor library internals and pin modes. Specify a color mode type. Valid modes are `TYPE_COLORFULL`, `TYPE_COLORRED`, `TYPE_COLORGREEN`, `TYPE_COLORBLUE`, `TYPECOLORNONE`. Call this function once for each instance during your setup() function.


# Color sensor status functions

#### `uint8_t getColor(void)`

Reads the sensor and returns a `COLOR_*` value. Colors are listed below in the enum section.


#### `void printColor(uint8_t color)`

Prints out a human-readable color name to the Serial port. Pass in the value you get from `getColor()`.


# Enumerations and constants

#### Mode types for `begin()`

* `TYPE_COLORFULL`
* `TYPE_COLORRED`
* `TYPE_COLORGREEN`
* `TYPE_COLORBLUE`
* `TYPE_COLORNONE`

#### Colors returned by `getColor()`

* `COLOR_BLACK`
* `COLOR_BLUE`
* `COLOR_GREEN`
* `COLOR_YELLOW`
* `COLOR_RED`
* `COLOR_WHITE`

