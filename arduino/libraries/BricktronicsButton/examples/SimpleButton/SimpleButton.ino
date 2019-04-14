// Bricktronics Example: SimpleButton
// http://www.wayneandlayne.com/bricktronics
// This example uses a LEGO NXT Pushbutton sensor.
//
// This example transmits a "pressed" and "released" over the serial port
// in response to button presses and releases.
//
// Written in 2015 by Matthew Beckler and Adam Wolf for Wayne and Layne, LLC
// To the extent possible under law, the author(s) have dedicated all
//   copyright and related and neighboring rights to this software to the
//   public domain worldwide. This software is distributed without any warranty.
// You should have received a copy of the CC0 Public Domain Dedication along
//   with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>. 


// Include the Bricktronics Button libraries
#include <BricktronicsButton.h>

// 2. With a Bricktronics Megashield - Include these lines but do not
// call BricktronicsShield::begin() in the setup() function below.
// Select the desired sensor port (SENSOR_1 through SENSOR_4) in the constructors below.
// Connect pins 2-3 and 4-5 on the chosen sensor port.
//
// Config 2 - arduino:avr:mega:cpu=atmega2560
#include <BricktronicsMegashield.h>
BricktronicsButton b(BricktronicsMegashield::SENSOR_1);
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

  // Initialize the button connection
  b.begin();
}

void loop()
{
  // Wait until the button is pressed
  while (b.isReleased())
  {
    // Nothing to do here
  }
  // To get here, the button was pushed!

  // In order to debounce the button, we transmit a message on the serial
  // port and then wait a little bit longer here.
  Serial.println("pressed");
  delay(100);
  
  // Wait until the button is released
  while (b.isPressed())
  {
    // Nothing to do here
  }

  // In order to debounce the button, we transmit a message on the serial
  // port and then wait a little bit longer here.
  Serial.println("released");
  delay(100);
}

