BricktronicsMegashield
======================

**BricktronicsMegashield v1.2 - A software library for Arduino.**

This meta-library provides easy interfacing to the [Bricktronics Megashield](https://store.wayneandlayne.com/products/bricktronics-megashield-kit.html). This library does not contain any functional code, rather it provides static mappings between motor and sensor ports on the Megashield, and the pin numbers needed by the motor and sensor libraries. It packages the pin settings into two structs defined in [BricktronicsSettings.h](utility/BricktronicsSettings.h), which are defined as static const objects in the BricktronicsMegashield class. Use these objects in your motor and sensor constructors.

More details at http://www.wayneandlayne.com/bricktronics/

To download. click the "Download ZIP" button on the right side of this page. Rename the uncompressed folder BricktronicsMegashield. Check that the BricktronicsMegashield folder contains BricktronicsMegashield.cpp and BricktronicsMegashield.h

Place the BricktronicsMegashield library folder into your `<arduinosketchfolder>/libraries/` folder. You may need to create the libraries subfolder if this is your first installed library. Restart the Arduino IDE.

**API Highlights**
* `BricktronicsShield::MOTOR_1` - Use this static const struct in your motor constructors. `MOTOR_1` through `MOTOR_6` are defined.
* `BricktronicsShield::SENSOR_1` - Use this static const struct in your sensor constructors. `SENSOR_1` through `SENSOR_4` are defined.
* More API details in [API.md](API.md)

**Supported motor and sensor libraries you may be interested in:**
* [BricktronicsMotor](https://github.com/wayneandlayne/BricktronicsMotor) – Support for NXT 2.0 and EV3 servomotors
* [BricktronicsLight](https://github.com/wayneandlayne/BricktronicsLight) – Support for monochrome light sensor
* [BricktronicsColor](https://github.com/wayneandlayne/BricktronicsColor) – Support for color sensors
* [BricktronicsSound](https://github.com/wayneandlayne/BricktronicsSound) – Support for sound sensors
* [BricktronicsButton](https://github.com/wayneandlayne/BricktronicsButton) – Support for pushbutton sensors
* [BricktronicsUltrasonic](https://github.com/wayneandlayne/BricktronicsUltrasonic) – Support for the NXT 2.0 ultrasonic sensor

**If you want to automatically verify all configurations of the library example sketches, you need to download the W&L VerifySketchConfig library so that the symbolic link works:**
* [VerifySketchConfig](https://github.com/wayneandlayne/VerifySketchConfig/)

_Wayne and Layne, LLC and our products are not connected to or endorsed by the LEGO Group. LEGO, Mindstorms, and NXT are trademarks of the LEGO Group._

