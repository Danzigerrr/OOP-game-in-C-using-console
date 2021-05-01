#include "Z_Wilk.h"

Wilk::Wilk(){
	this->sila = 9;
	this->inicjatywa = 5;
}
Wilk::Wilk(Swiat* swiat, const COORDINATES pos, int wiek) {
	this->wiek = wiek;
	this->sila = 9;
	this->inicjatywa = 5;
	this->swiat = swiat;
	this->pozycja = pos;
}

Wilk::~Wilk() {}

const char Wilk::GetZnak() {
	return WILK;
}

void Wilk::Akcja() {

}

void Wilk::Kolizja(Organizm* atakujacy) {
    if (sila != atakujacy->GetSila()) //sily sa rozne --> wygyrwa silniejszy
    {
        if (sila > atakujacy->GetSila()) //wygrywa czlowiek
        {
            delete atakujacy;
            Organizm*** plansza = swiat->GetPlansza();
            plansza[pozycja.x][pozycja.y] = new Trawa();
        }
        else //wygrywa atakujacy
        {
            delete this;
        }
    }

    else //jesli sily sa rowne --> wygrywa atakujacy
    {
        delete this;
    }
}