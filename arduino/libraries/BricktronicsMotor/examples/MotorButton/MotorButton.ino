// Bricktronics Example: MotorButton
// http://www.wayneandlayne.com/bricktronics
// This example uses a LEGO NXT Motor and a Pushbutton sensor.
//
// This example starts the motor at full speed, then waits for
// the button to be pressed and released, then reverses direction.
// It does this forever! (or until you turn off the power,
// unplug stuff, or reprogram the Arduino.)
//
// This example uses a motor, so it needs more power than a USB port can give.
// We really don't recommend running motors off of USB ports (they will be
// slow and sluggish, other things won't quite work right, things can get hot)
// it's just not a good idea.  Use an external power supply that provides
// between 7.2 and 9 volts DC, and can provide at least 600 mA per motor
// (1 amp preferably). Two options that work really well are a 9V wall adapter
// or a 6xAA battery pack (2.1mm plug, center positive).
//
// Written in 2015 by Matthew Beckler and Adam Wolf for Wayne and Layne, LLC
// To the extent possible under law, the author(s) have dedicated all
//   copyright and related and neighboring rights to this software to the
//   public domain worldwide. This software is distributed without any warranty.
// You should have received a copy of the CC0 Public Domain Dedication along
//   with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>. 


// Include the Bricktronics Motor library and helper libraries
// Helper libraries can be downloaded from:
// https://www.pjrc.com/teensy/td_libs_Encoder.html
// https://github.com/br3ttb/Arduino-PID-Library/
//	Be sure to rename unzipped folder PID_v1
#include <Encoder.h>
#include <PID_v1.h>
#include <BricktronicsMotor.h>
// Include the Bricktronics Button libraries
#include <BricktronicsButton.h>


// This example can be run in three different ways. Pick one, and un-comment
// the code lines corresponding to your chosen method. Comment-out the lines
// for the other methods that you aren't using.


// 2. With a Bricktronics Megashield - Include these lines but do not
// call BricktronicsShield::begin() in the setup() function below.
// Select the desired motor port (MOTOR_1 through MOTOR_6) and sensor port
// (SENSOR_1 through SENSOR_4) in the constructors below.
// Connect pins 2-3 and 4-5 on the chosen sensor port.
//
// Config 2 - CFG_WNL_BMS
#include <BricktronicsMegashield.h>
BricktronicsMotor m(BricktronicsMegashield::MOTOR_1);
BricktronicsButton b(BricktronicsMegashield::SENSOR_1);
// Config end

void setup()
{
  // Only call this if you are using a Bricktronics Shield,
  // otherwise leave it commented-out.
  // Config 1 - CFG_WNL_BS
  //BricktronicsShield::begin();
  // Config end

  // Initialize the motor and button connections
  m.begin();
  b.begin();
}

int theSpeed = 150;

void loop()
{
  m.setFixedDrive(theSpeed);
  
  // Wait until the button is pressed
  while (b.isReleased())
  {
    // Nothing to do here
  }
  // To get here, the button was pushed!

  // While the button is held down, turn on the dynamic brake
  m.brake();

  // In order to debounce the button, we wait a little bit here
  delay(100);
  
  // Wait until the button is released
  while (b.isPressed())
  {
    // Nothing to do here
  }

  // In order to debounce the button, we wait a little bit here
  delay(100);

  // Reverse direction
  theSpeed *= -1;
}

