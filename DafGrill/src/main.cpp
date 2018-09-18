#include <Arduino.h>
#include <Stepper.h>
#include "max6675.h"

const uint8_t stepperRotationSteps = 200;
enum spearMotorPins {A = 9, B, C, D};
Stepper MotorSpear(stepperRotationSteps, spearMotorPins::A,spearMotorPins::B, spearMotorPins::C,spearMotorPins::D);

int diode[] = {11, 12, 13}; //Array med dioder
enum tempPins {SCK = 6, CS, SO};

int currentTemp = 0;

MAX6675 temp(tempPins::SCK, tempPins::CS, tempPins::SO);

void setup() {
    // put your setup code here, to run once:
    MotorSpear.setSpeed(4);
}

void loop() {
    //Her indsætter vi den kode som skal køre gentagende gange
    MotorSpear.step(1);

    currentTemp = temp.readCelsius();

    if (currentTemp < 20) { //Tænder den først diode og slukker de andre hvis temp < 190
        digitalWrite(diode[0], HIGH);
        digitalWrite(diode[1], LOW);
        digitalWrite(diode[2], LOW);
    }
    else if (currentTemp < 22) { //Tænder den anden diode og slukker de andre hvis temp < 210
        digitalWrite(diode[0], LOW);
        digitalWrite(diode[1], HIGH);
        digitalWrite(diode[2], LOW);
    }
    else { //Tænder den tredje diode og slukker de andre hvis temp > 210
        digitalWrite(diode[0], LOW);
        digitalWrite(diode[1], LOW);
        digitalWrite(diode[2], HIGH);
    }
}