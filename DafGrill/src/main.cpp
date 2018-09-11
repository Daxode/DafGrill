#include <Arduino.h>
#include <Stepper.h>
#include "max6675.h"

<<<<<<< HEAD
const uint8_t stepperRotationSteps = 200;
Stepper MotorSpear(stepperRotationSteps, 9,10,11,12);

void setup() {
    // put your setup code here, to run once:
    MotorSpear.setSpeed(6);
=======
//Stepper MotorSpear = Stepper(200, 9,10,11,12);

int diode[] = {11, 12, 13}; //Array med dioder
int currentTemp = 0;
int tempSO = 8;
int tempCS = 7;
int tempSCK = 6;

MAX6675 temp(tempSCK, tempCS, tempSO);

void setup() {
    // put your setup code here, to run once:
   // MotorSpear.setSpeed(0);
    pinMode(13, OUTPUT); //Sætter pin 13 til output
    pinMode(12, OUTPUT); //Sætter pin 12 til output
    pinMode(11, OUTPUT); //Sætter pin 11 til output
    Serial.begin(9600);
    delay(500);
>>>>>>> 62085d96555e196ea26efe0f877a99cbab3ebb75
}

void loop() {
    // put your main code here, to run repeatedly:
<<<<<<< HEAD
    MotorSpear.step(1);
=======
  //  MotorSpear.step(60);

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
>>>>>>> 62085d96555e196ea26efe0f877a99cbab3ebb75
}