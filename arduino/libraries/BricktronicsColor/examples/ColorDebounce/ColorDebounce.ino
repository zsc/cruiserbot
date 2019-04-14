// Bricktronics Example: ColorButton
// http://www.wayneandlayne.com/bricktronics
// This example uses a LEGO NXT Color Sensor.
//
// Color sensor readings are taken repeatedly, and when they change,
// they're debounces so the colors don't switch back and forth on a
// transition. The debounced color is printed to the serial console.
// This isn't necessarily the simplest or best way to debounce,
// but it works for what we're using it for!
//
// Written in 2015 by Matthew Beckler and Adam Wolf for Wayne and Layne, LLC
// To the extent possible under law, the author(s) have dedicated all
//   copyright and related and neighboring rights to this software to the
//   public domain worldwide. This software is distributed without any warranty.
// You should have received a copy of the CC0 Public Domain Dedication along
//   with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>. 


// Include the Bricktronics ColorSensor library
#include <BricktronicsColor.h>


// This example can be run in three different ways. Pick one, and un-comment
// the code lines corresponding to your chosen method. Comment-out the lines
// for the other methods that you aren't using.

// 2. With a Bricktronics Megashield - Include these lines but do not
// call BricktronicsShield::begin() in the setup() function below.
// Select the sensor port (SENSOR_1 through SENSOR_4) in the constructor below.
// Use the jumpers to connect only pins 3-4 for the color sensor.
//
// Config 2 - arduino:avr:mega:cpu=atmega2560
#include <BricktronicsMegashield.h>
BricktronicsColor c(BricktronicsMegashield::SENSOR_3);
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

  // Initialize the color sensor connections
  c.begin();
}

char stable = 0;
char lastColor = c.getColor();
char newReading;

void loop()
{
  stable = 0;
  newReading = c.getColor();

  if (newReading != lastColor)
  {
    while (stable < 10)
    {
      delay(10);

      if (c.getColor() == newReading)
      {
        stable += 1;
      }
      else
      {
        newReading = c.getColor();
        stable = 0;
      }
    }

    if (newReading != lastColor)
    {
      c.printColor(newReading);
      Serial.println();
      lastColor = newReading;
    }
  }

  delay(10);
}

