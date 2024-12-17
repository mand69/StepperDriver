#include <Arduino.h>
#include <AccelStepper.h>

#define STEP_PIN 18
#define DIR_PIN 19

AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

void setup() {
  stepper.setMaxSpeed(400);
  stepper.setAcceleration(100);
}

void loop() {
  stepper.moveTo(50);
  while (stepper.distanceToGo() != 0) {
    stepper.run();
  }
  
  delay(1000);
  
  stepper.moveTo(0);
  while (stepper.distanceToGo() != 0) {
    stepper.run();
  }
  
  delay(1000);
}