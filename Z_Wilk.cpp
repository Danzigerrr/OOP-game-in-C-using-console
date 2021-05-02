#include "Z_Wilk.h"
#include "Swiat.h"
Wilk::Wilk(){
    init();
}
Wilk::Wilk(Swiat* swiat, const COORDINATES pos, int wiek) {
    init();
    this->wiek = wiek;
    this->swiat = swiat;
    this->pozycja = pos;
}

Wilk::~Wilk() {}

void Wilk::init() {
    this->sila = 9;
    this->inicjatywa = 5;
    this->znak = WILK;
}

