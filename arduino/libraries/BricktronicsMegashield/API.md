# BricktronicsMegashield API

This meta-library provides easy interfacing to the [Bricktronics Megashield](https://store.wayneandlayne.com/products/bricktronics-megashield-kit.html). This library does not contain any functional code, rather it provides static mappings between "sensor ports" on the Megashield and pin numbers needed by the motor and sensor libraries. It packages the pin settings into two structs defined in [BricktronicsSettings.h](utility/BricktronicsSettings.h), which are defined as static const objects in the BricktronicsMegashield class. Use these objects in your motor and sensor constructors.

# Supported motor and sensor libraries

* [BricktronicsMotor](https://github.com/wayneandlayne/BricktronicsMotor) – Support for NXT 2.0 and EV3 servomotors
* [BricktronicsLight](https://github.com/wayneandlayne/BricktronicsLight) – Support for monochrome light sensor
* [BricktronicsColor](https://github.com/wayneandlayne/BricktronicsColor) – Support for color sensors
* [BricktronicsSound](https://github.com/wayneandlayne/BricktronicsSound) – Support for sound sensors
* [BricktronicsButton](https://github.com/wayneandlayne/BricktronicsButton) – Support for pushbutton sensors
* [BricktronicsUltrasonic](https://github.com/wayneandlayne/BricktronicsUltrasonic) – Support for the NXT 2.0 ultrasonic sensor

# Quick Example

Use the BricktronicsMegashied library to provide details on the pin connections for a pushbutton sensor to any sensor port on the Bricktronics Megashield. Use the jumpers to connect pins 2-3 and 4-5.

```C++
#include <BricktronicsMegashield.h>
#include <BricktronicsButton.h>

// Declare the sensor is connected to sensor port 1
BricktronicsButton b(BricktronicsMegashield::SENSOR_1);

void setup()
{
    Serial.begin(115200);
    b.begin();
}

void loop()
{
    delay(500);
    while(b.isReleased());
    Serial.println("pressed");
    delay(100);

    while(b.isPressed());
    Serial.println("released");
    delay(100);
}
```

# Motor settings

#### `BricktronicsShield::MOTOR_1`
#### `BricktronicsShield::MOTOR_2`
#### `BricktronicsShield::MOTOR_3`
#### `BricktronicsShield::MOTOR_4`
#### `BricktronicsShield::MOTOR_5`
#### `BricktronicsShield::MOTOR_6`

# Sensor settings

#### `BricktronicsShield::SENSOR_1`
#### `BricktronicsShield::SENSOR_2`
#### `BricktronicsShield::SENSOR_3`
#### `BricktronicsShield::SENSOR_4`

