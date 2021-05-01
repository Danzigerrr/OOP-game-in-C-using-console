#include "Z_Lis.h"


Lis::Lis() {
	this->sila = 3;
	this->inicjatywa = 7;
}
Lis::Lis(Swiat* swiat, const COORDINATES pos, int wiek) {
	this->wiek = wiek;
	this->sila = 3;
	this->inicjatywa = 7;
	this->swiat = swiat;
	this->pozycja = pos;
}

Lis::~Lis() {}

const char Lis::GetZnak() {
	return LIS;
}

void Lis::Akcja() {

}


void Owca::Kolizja(Organizm* atakujacy) {
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

