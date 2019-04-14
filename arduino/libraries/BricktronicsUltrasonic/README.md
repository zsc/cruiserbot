BricktronicsUltrasonic
======================

**BricktronicsUltrasonic v1.2 - A software library for LEGO NXT ultrasonic sensors.**

More details at http://www.wayneandlayne.com/bricktronics/

To download. click the "Download ZIP" button on the right side of this page. Rename the uncompressed folder BricktronicsUltrasonic. Check that the BricktronicsUltrasonic folder contains BricktronicsUltrasonic.cpp and BricktronicsUltrasonic.h

Place the BricktronicsUltrasonic library folder into your `<arduinosketchfolder>/libraries/` folder. You may need to create the libraries subfolder if this is your first installed library. Restart the Arduino IDE.

**API Highlights**
* `BricktronicsUltrasonic(uint8_t sclPin, uint8_t sdaPin)` - Constructor
* `void begin()` - Call the begin function in your setup() function
* `uint8_t getDistance()` - Basic ultrasonic sensor read function. Returns the latest sensor reading, returns 0 in case of error. Measured distance is in units of centimeters.
* More API details in [API.md](API.md)

**If you want to use ultrasonic sensors with your Bricktronics Shield or Megashield, you may also be interested in these libraries:**
* [BricktronicsShield Arduino Library v1.2](https://github.com/wayneandlayne/BricktronicsShield)
* [BricktronicsMegashield Arduino Library v1.2](https://github.com/wayneandlayne/BricktronicsMegashield)

**If you want to automatically verify all configurations of the library example sketches, you need to download the W&L VerifySketchConfig library so that the symbolic link works:**
* [VerifySketchConfig](https://github.com/wayneandlayne/VerifySketchConfig/)

_Wayne and Layne, LLC and our products are not connected to or endorsed by the LEGO Group. LEGO, Mindstorms, and NXT are trademarks of the LEGO Group._

