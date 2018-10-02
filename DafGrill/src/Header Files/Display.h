#include "LiquidCrystal.h"
#include <Arduino.h>

//Dette er filen som beskriver hvordan styringen af et LCD display.
class Display {
    private:
    //Dette er de porte som er forbundet til vores display
        enum displayPins {
            Vss = 0,
            Vdd = 0,
            V0 = 82,
            RS = 44,    //Vælg display data ("H") eller instruktioner ("L")
            RW = 0,     //Læs eller skriv vælge signal
            E = 45,     //Læs/skriv tilladelses signal
            DB0,
            DB1,
            DB2,
            DB3,
            DB4 = 46,
            DB5,
            DB6,
            DB7,
            LEDNeg = 0, 
            LedPos = 0
        };
        
        LiquidCrystal lcd = LiquidCrystal(displayPins::RS, displayPins::E, displayPins::DB4, displayPins::DB5, displayPins::DB6, displayPins::DB7);

    public:
        //For ikke at skrive hvert enkelte bogstav så kan vi med denne funktion skrive strenge til vores display.
        void WriteString(const char* msg);
        
        //For at aktivere displayet
        void Activate();
};