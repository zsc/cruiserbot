#include <Stepper.h>

#define STEPS 100

Stepper stepper(STEPS, 8, 9, 10, 11);

void setup() {
  stepper.setSpeed();
}


void loop() {
  stepper.step(5786);
  delay(3000);
}

