// Bricktronics Example: MotorSingle
// http://www.wayneandlayne.com/bricktronics
// This example uses a LEGO NXT Motor.
//FFFFFHBL..KJMNCZx';
// This example starts the motor at an intermediate speed,
// then speeds it up to full speed, and does the same in reverse.
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


// This example can be run in three different ways. Pick one, and un-comment
// the code lines corresponding to your chosen method. Comment-out the lines
// for the other methods that you aren't using.

// 2. With a Bricktronics Megashield - Include these lines below but do not
// call BricktronicsShield::begin() in the setup() function below. Select the
// desired motor port (MOTOR_1 through MOTOR_6) in the constructor below.
//
// Config 2 - CFG_WNL_BMS  
#include <BricktronicsMegashield.h>
BricktronicsMotor m1(BricktronicsMegashield::MOTOR_1);
//BricktronicsMotor m2(BricktronicsMegashield::MOTOR_2);
//BricktronicsMotor m3(BricktronicsMegashield::MOTOR_3);
//BricktronicsMotor m4(BricktronicsMegashield::MOTOR_4);
//BricktronicsMotor m5(BricktronicsMegashield::MOTOR_5);
//BricktronicsMotor m6(BricktronicsMegashield::MOTOR_6);

// Config end

int speed = 10;
int inByte;
void setup()
{
  // Be sure to set your serial console to 115200 baud
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // Only call this line if you are using a Bricktronics Shield,
  // otherwise leave it commented-out.
  // Config 1 - CFG_WNL_BS
  //BricktronicsShield::begin();
  // Config end

  // Initialize the motor connections
  m1.begin();
  //m2.begin();
  //m3.begin();
  //m4.begin();
  //m5.begin();
  //m6.begin();
  pinMode(13, OUTPUT);
  establishContact();  // send a byte to establish contact until receiver responds
  //speed = 10;
}

void loop()
{
  //m1.setAngleOutputMultiplier(1);
  //speed = 10;
  if (Serial.available() > 0) { 
      inByte = Serial.read();
      if (inByte == 65) {
        digitalWrite(13, HIGH);
        speed = 100;
      } else {
        digitalWrite(13, LOW);
        speed = -100;
      }
      //Serial.print(speed);
  }
  //m1.goToAngle(30);
  //m1.delayUpdateMS(1000);
  m1.setFixedDrive(speed);
  //m2.setFixedDrive(255);
  //m3.setFixedDrive(255);
  //m4.setFixedDrive(255);
  //m5.setFixedDrive(255);
  //m6.setFixedDrive(255);

  delay(2000);
  //m1.goToAngleWaitForArrival(-30);
  //m1.delayUpdateMS(1000);
  //m1.goToAngle(-30);
//  m1.setFixedDrive(-speed);
  //m2.setFixedDrive(-255);
  //m3.setFixedDrive(-255);
  //m4.setFixedDrive(-255);
  //m5.setFixedDrive(-255);
  //m6.setFixedDrive(-255);

  //delay(2000);
}

void establishContact() {
  while (Serial.available() <= 0) {
    Serial.print('A');   // send a capital A
    delay(300);
  }
}

