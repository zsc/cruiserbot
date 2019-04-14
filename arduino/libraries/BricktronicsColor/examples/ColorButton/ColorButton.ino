// Bricktronics Example: ColorButton
// http://www.wayneandlayne.com/bricktronics
// This example uses a LEGO NXT Pushbutton Sensor and Color Sensor.
// 
// When the button is pressed, a single reading from the color sensor is taken
// and converted into a color name and printed over the Serial Console.
//
// Written in 2015 by Matthew Beckler and Adam Wolf for Wayne and Layne, LLC
// To the extent possible under law, the author(s) have dedicated all
//   copyright and related and neighboring rights to this software to the
//   public domain worldwide. This software is distributed without any warranty.
// You should have received a copy of the CC0 Public Domain Dedication along
//   with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>. 


// Include the Bricktronics Button and ColorSensor libraries
#include <BricktronicsButton.h>
#include <BricktronicsColor.h>


// This example can be run in three different ways. Pick one, and un-comment
// the code lines corresponding to your chosen method. Comment-out the lines
// for the other methods that you aren't using.

// 2. With a Bricktronics Megashield - Include these lines but do not
// call BricktronicsShield::begin() in the setup() function below.
// Select the sensor ports for the button (SENSOR_1 through SENSOR_4)
// and color sensor (SENSOR_1 through SENSOR_4) in their constructors below.
// If your chosen port has jumpers, connect pins 2-3 and 4-5 for the button,
// and connect only pins 3-4 for the color sensor.
//
// Config 2 - arduino:avr:mega:cpu=atmega2560
#include <BricktronicsMegashield.h>
BricktronicsButton b(BricktronicsMegashield::SENSOR_1);
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

  // Initialize the button and color sensor connections
  b.begin();
  c.begin();
}


void loop()
{
  // Wait until the button is pressed
  while (b.isReleased())
  {
    // Nothing to do here
  }
  // To get here, the button was pushed!

  c.printColor(c.getColor());
  Serial.println();

  // In order to debounce the button, we wait a little bit here
  delay(100);

  // Wait until the button is released
  while (b.isPressed())
  {
    // Nothing to do here
  }

  // In order to debounce the button, we wait a little bit here
  delay(100);
}

