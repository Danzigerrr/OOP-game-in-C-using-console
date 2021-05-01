#include "Z_Antylopa.h"


Antylopa::Antylopa() {
	this->sila = 4;
	this->inicjatywa = 4;
}
Antylopa::Antylopa(Swiat* swiat, const COORDINATES pos, int wiek) {
	this->wiek = wiek;
	this->sila = 4;
	this->inicjatywa = 4;
	this->swiat = swiat;
	this->pozycja = pos;
}

Antylopa::~Antylopa() {}

const char Antylopa::GetZnak() { return ANTYLOPA; }

void Antylopa::Akcja() {

}


void Owca::Kolizja(Organizm* atakujacy) {
    bool AntylopaUcieka = rand() % 1;
    if (AntylopaUcieka) {
        for(int i=0;i<3;i++)
            for (int j = 0; j < 3; j++) {
                int Xpos = pozycja.x - 1 + i;
                int Ypos = pozycja.y - 1 + i;
                if (swiat->GetPlansza()[Xpos][Ypos]->GetZnak() == '_') { //szukanie pola z Trawa
                    pozycja.x = Xpos;
                    pozycja.y = Ypos;
                    swiat->GetPlansza()[Xpos][Ypos] = this;
                }
            }
    }

    else { //normalna kolizja

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
}

