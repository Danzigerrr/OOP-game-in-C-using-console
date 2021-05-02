#include "R_BarszczSosnowskiego.h"
#include "Swiat.h"


BarszczSosnowskiego::BarszczSosnowskiego() {
	init();
}
BarszczSosnowskiego::BarszczSosnowskiego(Swiat* swiat, const COORDINATES pos, int wiek) {
	init();
	this->wiek = wiek;
	this->swiat = swiat;
	this->pozycja = pos;
}

void BarszczSosnowskiego::init() {
	this->sila = 10;
	this->znak = BARSZCZ;
}

BarszczSosnowskiego::~BarszczSosnowskiego() {}

//Zwierze które zjadło tę roślinę ginie.Jedynie
void BarszczSosnowskiego::Kolizja(Organizm* atakujacy) {
	
    if (sila != atakujacy->GetSila()) //sily sa rozne --> wygyrwa silniejszy
    {
        if (sila > atakujacy->GetSila()) //wygrywa czlowiek
        {
            cout << this->GetZnak() << " wygral\n";
            delete atakujacy;
            Organizm*** plansza = swiat->GetPlansza();
            plansza[pozycja.x][pozycja.y] = new Trawa();
        }
        else //wygrywa atakujacy
        {
            cout << atakujacy->GetZnak() << " wygral\n";
            delete atakujacy;
            delete this;
        }
    }

    else //jesli sily sa rowne --> wygrywa atakujacy
    {
        cout << atakujacy->GetZnak() << " wygral\n";
        delete atakujacy;
        delete this;
    }

}


//Zabija wszystkie zwierzęta w swoim sąsiedztwie poza
void BarszczSosnowskiego::Akcja() {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			int Xpos = pozycja.x - 1 + i;
			int Ypos = pozycja.y - 1 + i;

			if (Xpos < swiat->GetSzerokosc() && Ypos < swiat->GetWysokosc())//wtedy szuka tylko w zaalokowanej pamieci
				swiat->GetPlansza()[Xpos][Ypos] = new Trawa();
		}
}
