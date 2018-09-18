//Dette er filen som beskriver hvordan styringen af et LCD display.
class display {
    //Dette er de porte som er forbundet til vores display
    int dataPins[16];
    
    public:
        //Vi skal bruge en metode til at skrive bogstaver i speciffikke posistioner.
        void writeLetterToPos(int pos, char letter);

        //For ikke at skrive hvert enkelte bogstav så kan vi med denne funktion skrive strenge til vores display.
        void writeString(char* toDisplay);
}

enum displaydataPins {
    
}