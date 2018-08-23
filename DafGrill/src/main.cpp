#include <Arduino.h>
#include <Stepper.h>

Stepper MotorSpear = Stepper(200, 9,10,11,12);

void setup() {
    // put your setup code here, to run once:
    MotorSpear.setSpeed(0);
}

void loop() {
    // put your main code here, to run repeatedly:
    MotorSpear.step(60);
}