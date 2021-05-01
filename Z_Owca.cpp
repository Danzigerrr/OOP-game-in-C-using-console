#include "Z_Owca.h"


Owca::Owca() {
	this->sila = 4;
	this->inicjatywa = 4;
}
Owca::Owca(Swiat* swiat, const COORDINATES pos, int wiek) {
	this->wiek = wiek;
	this->sila = 4;
	this->inicjatywa = 4;
	this->swiat = swiat;
	this->pozycja = pos;
}


Owca::~Owca() {}

const char Owca::GetZnak() {
	return OWCA;
}

void Owca::Akcja() {

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