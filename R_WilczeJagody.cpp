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



