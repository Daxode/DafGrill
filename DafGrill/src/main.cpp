#include <Arduino.h>
#include <Stepper.h>

const uint8_t stepperRotationSteps = 200;
Stepper MotorSpear(stepperRotationSteps, 9,10,11,12);

void setup() {
    // put your setup code here, to run once:
    MotorSpear.setSpeed(100);
}

void loop() {
    // put your main code here, to run repeatedly:
    MotorSpear.step(1);
}