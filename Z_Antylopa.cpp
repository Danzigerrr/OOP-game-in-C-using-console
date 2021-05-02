#include "Z_Antylopa.h"


Antylopa::Antylopa() {
    init();
}
Antylopa::Antylopa(Swiat* swiat, const COORDINATES pos, int wiek) {
    init();
	this->wiek = wiek;
	this->swiat = swiat;
	this->pozycja = pos;
}

void Antylopa::init() {
    this->sila = 4;
    this->inicjatywa = 4;
    this->step = 2;
    this->znak = ANTYLOPA;
}

Antylopa::~Antylopa() {}


void Antylopa::Kolizja(Zwierze* atakujacy, DIRECTION dir)
{
    bool AntylopaUcieka = rand() % 1;

    if (AntylopaUcieka) {
        for(int i=0;i<3;i++)
            for (int j = 0; j < 3; j++) {
                int Xpos = pozycja.x - 1 + i;
                int Ypos = pozycja.y - 1 + i;

                if(Xpos < swiat->GetSzerokosc() && Ypos < swiat->GetWysokosc() && Xpos >= 0 && Ypos >= 0)//wtedy szuka tylko w zaalokowanej pamieci
                    if (swiat->GetPlansza()[Xpos][Ypos]->GetZnak() == TRAWA) { //szukanie pola z Trawa
                        pozycja.x = Xpos;
                        pozycja.y = Ypos;
                        swiat->GetPlansza()[Xpos][Ypos] = this;
                    }
            }
    }

    else { 
        NormalnaKolizja(atakujacy, dir);
    }
}

