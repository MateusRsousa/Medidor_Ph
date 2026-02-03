#include "Display.h"


Display::Display(int address, int columns, int rows) 
    : address(address), columns(columns), rows(rows), lcd(address, columns, rows) {}


void Display::init() {
    lcd.init();
}


void Display::backlight() {
    lcd.backlight();
}


void Display::clear() {
    lcd.clear();
}


void Display::print(float value , int CasasDecimais) {
    lcd.print("Ph:");
    lcd.print(value, CasasDecimais);
}

void Display::print(const String& text) { // Implementação para Strings
    lcd.print(text);
}


void Display::setCursor(int linha , int coluna) {
    lcd.setCursor(linha, coluna);
}
