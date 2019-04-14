BricktronicsLight
=================

**BricktronicsLight v1.2 - A software library for LEGO NXT light sensors.**

More details at http://www.wayneandlayne.com/bricktronics/

To download. click the "Download ZIP" button on the right side of this page. Rename the uncompressed folder BricktronicsLight. Check that the BricktronicsLight folder contains BricktronicsLight.cpp and BricktronicsLight.h

Place the BricktronicsLight library folder into your `<arduinosketchfolder>/libraries/` folder. You may need to create the libraries subfolder if this is your first installed library. Restart the Arduino IDE.

**API Highlights**
* BricktronicsLight(uint8_t inputPin, uint8_t lightPin) - Constructor
* void begin(void) - Call the begin function in your setup() function
* uint16_t value(void) - Basic light sensor read function, scale is 0 (very dark) to 1023 (very bright)
* uint8_t scaledValue(void) - Scales the raw value into an int between 0 and 100 (uses calibration values).
* void setFloodlight(bool enable) - If enabled the light will turn on just before the sensor is sampled.
* void setFloodlightAlways(bool enable) - Set the light to be always-on if enable = true.

**If you want to use light sensors with your Bricktronics Shield or Megashield, you may also be interested in these libraries:**
* [BricktronicsShield Arduino Library v1.2](https://github.com/wayneandlayne/BricktronicsShield)
* [BricktronicsMegashield Arduino Library v1.2](https://github.com/wayneandlayne/BricktronicsMegashield)

**If you want to automatically verify all configurations of the library example sketches, you need to download the W&L VerifySketchConfig library so that the symbolic link works:**
* [VerifySketchConfig](https://github.com/wayneandlayne/VerifySketchConfig/)

Many thanks to Filipe Janela and Francisco Janela for writing the intial version of this code. Those guys rock.

_Wayne and Layne, LLC and our products are not connected to or endorsed by the LEGO Group. LEGO, Mindstorms, and NXT are trademarks of the LEGO Group._

