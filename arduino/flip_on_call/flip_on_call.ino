/*
 * 
Modifed from
 http://www.arduino.cc/en/Tutorial/SerialCallResponse

 */

#include <Stepper.h>

#define STEPS 100

Stepper stepper(STEPS, 8, 9, 10, 11);
int inByte = 0;

void setup() {
  stepper.setSpeed(500);
  // start serial port at 9600 bps:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  //pinMode(2, INPUT);   // digital sensor is on digital pin 2
  establishContact();  // send a byte to establish contact until receiver responds
}

void loop() {
  // if we get a valid byte, read analog ins:
  if (Serial.available() > 0) {
    stepper.step(578);
    
    // get incoming byte:
    inByte = Serial.read();
    Serial.print(inByte);
    Serial.write("Pong");
    delay(100);
  }
  Serial.print('B');
}

void establishContact() {
  while (Serial.available() <= 0) {
    Serial.print('A');   // send a capital A
    delay(300);
  }
}



