#pragma
#include "Header Files/Display.h"

//Vi skal bruge en metode til at skrive bogstaver i speciffikke posistioner.
void Display::WriteLetterToPos(int pos, char letter){

}

//For ikke at skrive hvert enkelte bogstav så kan vi med denne funktion skrive strenge til vores display.
void Display::WriteString(const char* msg){
    lcd.clear();
    lcd.print(String(msg).substring(0, 8));
    lcd.setCursor(0,2);
    lcd.print(String(msg).substring(8, 15));
}

void Display::Activate(){
    analogWrite(Display::displayPins::V0, 102);
    lcd.begin(8,2);
}