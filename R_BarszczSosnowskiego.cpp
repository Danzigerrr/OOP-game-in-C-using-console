﻿#include "R_BarszczSosnowskiego.h"
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

//Zwierze które zjadło tę roślinę ginie
void BarszczSosnowskiego::Kolizja(Zwierze* atakujacy, DIRECTION dir) {
	
    if (sila != atakujacy->GetSila()) //sily sa rozne --> wygyrwa silniejszy
    {
        if (sila > atakujacy->GetSila()) //wygrywa obronca
        {
			ObroncaWygral(atakujacy, dir);
        }
        else //wygrywa atakujacy
        {
            ZabijAtakujacego(atakujacy,dir);
        }
    }

    else //jesli sily sa rowne --> wygrywa atakujacy
    {
        ZabijAtakujacego(atakujacy, dir);
    }

}


//Zabija wszystkie zwierzęta w swoim sąsiedztwie poza
void BarszczSosnowskiego::Akcja() {

	cout << "teraz barszcz niszczy sasiadow\n";

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			int X = pozycja.x - 1 + j;
			int Y = pozycja.y - 1 + i;
			COORDINATES coor{X, Y};

			if (	coor.x < swiat->GetSzerokosc() && coor.y < swiat->GetWysokosc() &&
					coor.x >= 0 &&					  coor.y >= 0 &&
					!(coor.x == pozycja.x &&		  coor.y == pozycja.y)
				)
			{
				zabijSasiada(coor);
			}
		}

	//cout << "\n oto swiat po zabicu sasiadow:" << endl;
	//swiat->RysujSwiat();
}

void BarszczSosnowskiego::zabijSasiada(COORDINATES coor) {
	swiat->SetPole(coor, new Trawa(swiat, coor, 0));
}