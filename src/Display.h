
#ifndef DISPLAY_H
#define DISPLAY_H

#include <LiquidCrystal_I2C.h>

class Display {
private:

    int address;
    int columns;
    int rows;
    LiquidCrystal_I2C lcd;

public:
    
    Display(int address, int columns, int rows);
    void init();
    void backlight();
    void clear();
    void print(float value, int CasasDecimais);
    void print(const String& text); // Sobrecarga para exibir textos
    void setCursor(int linha, int coluna);
};

#endif
