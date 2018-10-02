#include <Arduino.h>
#include <Stepper.h>
#include <Wire.h>
#include "max6675.h"
#include "Header Files/Display.h"

const uint8_t stepperRotationSteps = 200;
enum spearMotorPins {A = 50, B, C, D};
Stepper MotorSpear(stepperRotationSteps, (uint8_t)spearMotorPins::A, (uint8_t)spearMotorPins::B, (uint8_t)spearMotorPins::C, (uint8_t)spearMotorPins::D);

int currentTemp = 0;
enum tempPins {tSCK = 22, tCS, tSO};
MAX6675 temp(tempPins::tSCK, tempPins::tCS, tempPins::tSO);

Display testDisplay;
//LiquidCrystal lcd(Display::displayPins::RS, Display::displayPins::E, Display::displayPins::DB4, Display::displayPins::DB5, Display::displayPins::DB6, Display::displayPins::DB7);

void setup() {
    // put your setup code here, to run once:
    MotorSpear.setSpeed(4);
    
    testDisplay.Activate();
}

void loop() {
    //Her indsætter vi den kode som skal køre gentagende gange
    MotorSpear.step(1);
    
    //testDisplay.WriteString("PIZZA ER GODT!!!");
    testDisplay.WriteString((String(currentTemp) + (char)223 + "C").c_str());
    
    //Anskaf data om temp i celsius
    currentTemp = temp.readCelsius();
    delay(500);
}