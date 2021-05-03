#include "R_WilczeJagody.h"
#include "Swiat.h"
WilczeJagody::WilczeJagody() {
	init();

}
WilczeJagody::WilczeJagody(Swiat* swiat, const COORDINATES pos, int wiek) {
	init();
	this->wiek = wiek;
	this->swiat = swiat;
	this->pozycja = pos;
}
void WilczeJagody::init() {
	this->sila = 99;
	this->znak = WILCZEJAGODY;
}
WilczeJagody::~WilczeJagody() {}

//Zwierze które zjadło tę roślinę ginie 
void WilczeJagody::Kolizja(Zwierze* atakujacy, DIRECTION dir) {
    if (sila != atakujacy->GetSila()) //sily sa rozne --> wygyrwa silniejszy
    {
        if (sila > atakujacy->GetSila()) //wygrywa obronca
        {
            ObroncaWygral(atakujacy, dir);
        }
        else //wygrywa atakujacy
        {
            ZabijAtakujacego(atakujacy, dir);
        }
    }

    else //jesli sily sa rowne --> wygrywa atakujacy
    {
        ZabijAtakujacego(atakujacy, dir);
    }

}


