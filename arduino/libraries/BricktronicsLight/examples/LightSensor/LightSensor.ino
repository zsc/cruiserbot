// Bricktronics Example: Light sensor
// http://www.wayneandlayne.com/bricktronics
// This example uses a LEGO NXT Light Sensor.
//
// Light sensor readings are taken every 100 milliseconds, and
// printed out over the serial console. Be sure to set your serial
// console to 115200 baud. The light sensor library reports the measured
// light value with a unitless value between 0 (very dim) and
// 1023 (very bright). We can also set a calibration range, and the
// library can scale the raw value to a range of 0-100 based on the
// calibration values. Both these values are printed to the serial console.
//
// We also flash the Light Sensor's LED between each sample. We've found
// that the light doesn't help much in distinguishing between light and dark
// surfaces, but your mileage may vary, so give it a try.
//
// Written in 2015 by Matthew Beckler and Adam Wolf for Wayne and Layne, LLC
// To the extent possible under law, the author(s) have dedicated all
//   copyright and related and neighboring rights to this software to the
//   public domain worldwide. This software is distributed without any warranty.
// You should have received a copy of the CC0 Public Domain Dedication along
//   with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>. 


// Include the Bricktronics Light sensor library
#include <BricktronicsLight.h>


// This example can be run in three different ways. Pick one, and un-comment
// the code lines corresponding to your chosen method. Comment-out the lines
// for the other methods that you aren't using.

// 2. With a Bricktronics Megashield - Include these lines but do not
// call BricktronicsShield::begin() in the setup() function below.
// Select the sensor port for the light sensor (SENSOR_1 through SENSOR_4) below.
// Use the jumpers to connect pins 2-3 and 4-5 for the light sensor.
//
// Config 2 - arduino:avr:mega:cpu=atmega2560
#include <BricktronicsMegashield.h>
BricktronicsLight ls(BricktronicsMegashield::SENSOR_4);
// Config end



void setup() 
{
  // Be sure to set your serial console to 115200 baud
  Serial.begin(115200);

  // Only call this if you are using a Bricktronics Shield,
  // otherwise leave it commented-out.
  // Config 1 - arduino:avr:uno
  //BricktronicsShield::begin();
  // Config end

  // Initialize the light sensor connections
  ls.begin();
}


void loop()
{
  Serial.print("Raw value: ");
  Serial.print(ls.value());
  Serial.print(" - scaled value: ");
  Serial.println(ls.scaledValue());

  // Flash the light sensor's built-in led, just for fun
  ls.setFloodlightAlways(true);
  delay(100);
  ls.setFloodlightAlways(false);

  delay(500);
}

