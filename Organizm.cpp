#include "Organizm.h"
#include "Swiat.h"

Organizm::Organizm(){}
Organizm::~Organizm(){}

const char Organizm::GetZnak() {
    return znak;
}
int Organizm::GetSila() {
    return sila;
}
void Organizm::SetSila(int sila) {
    this->sila = sila;
}
int Organizm::GetInicjatywa() {
    return inicjatywa;
}
void Organizm::SetInicjatywa(int inicjatywa) {
    this->inicjatywa = inicjatywa;
}
COORDINATES Organizm::GetPozycja() {
    return pozycja;
}
void Organizm::SetPozycja(COORDINATES pos) {
    this->pozycja = pos;
}
int Organizm::GetWiek() {
    return wiek;
}
void Organizm::SetWiek(int wiek) {
    this->wiek = wiek;
}
Swiat* Organizm::GetSwiat() {
    return swiat;
}
void Organizm::SetSwiat(Swiat* swiat) {
    this->swiat = swiat;
}

void Organizm::NormalnaKolizja(Zwierze* atakujacy, DIRECTION dir) {
    if (sila != atakujacy->GetSila()) //sily sa rozne --> wygyrwa silniejszy
    {
        if (sila > atakujacy->GetSila()) //wygrywa obronca
        {
            cout << this->GetZnak() << " DEF wygral\n";

            COORDINATES coor = pozycja;
            Zwierze* Org = NULL;
            char gatunek = GetZnak();
            switch (gatunek) {
                case ANTYLOPA: { Org = new Antylopa(swiat, coor, wiek); }break;
                case LIS: { Org = new Lis(swiat, coor, wiek); }break;
                case OWCA: { Org = new Owca(swiat, coor, wiek); }break;
                case WILK: {  Org = new Wilk(swiat, coor, wiek); }break;
                case ZOLW: { Org = new Zolw(swiat, coor, wiek); }break;
                case CZLOWIEK: { Org = new Czlowiek(swiat, coor, wiek); }break;
            }

            swiat->SetPole(pozycja, Org);
        }
        else //wygrywa atakujacy
        {
            if (GetSwiat() == NULL) cout << "NULL pointer";

            cout << "    " << atakujacy->GetZnak() << " ATT wygral z " << GetZnak() << endl;

            cout << "99999999";

            //ustawianie trawy na poprzednim polu atakujacego
            if (true) {
                COORDINATES stare = atakujacy->GetPozycja();
                int atakStep = atakujacy->GetStep();
                COORDINATES starecoor = stare;

                switch(dir) {
                case UP:{
                    starecoor.y += atakStep;
                }break;
                case DOWN: {
                    starecoor.y -= atakStep;
                }break;
                case LEFT: {
                    starecoor.x += atakStep;
                }break;
                case RIGHT: {
                    starecoor.x -= atakStep;
                }break;
                }

                swiat->SetPole(starecoor, new Mlecz(swiat, starecoor, 0));
            }

            swiat->SetPole(pozycja, atakujacy);
        }
    }

    else //jesli sily sa rowne --> wygrywa atakujacy
    {
        cout << "    " << atakujacy->GetZnak() << " ATT wygral z " << GetZnak() << endl;
     /*   swiat->SetPole(atakujacy->GetPozycja(), new Trawa());
        swiat->SetPole(pozycja, atakujacy);*/

        cout << "7777777";
    }
}
void Organizm::Kolizja(Zwierze* atakujacy, DIRECTION dir) {
    NormalnaKolizja(atakujacy, dir);
}
