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
        if (sila > atakujacy->GetSila()) 
            ObroncaWygral(atakujacy,dir);
        else 
            AtakujacyWygral(atakujacy, dir);
    }
    else //sily sa rowne --> wygrywa atakujacy
        AtakujacyWygral(atakujacy, dir);
}
void Organizm::Kolizja(Zwierze* atakujacy, DIRECTION dir) {
    NormalnaKolizja(atakujacy, dir);
}

void Organizm::AtakujacyWygral(Zwierze* atakujacy, DIRECTION dir) {
    cout << "    " << atakujacy->GetZnak() << " ATT wygral z " << GetZnak() << endl;

    //ustawianie trawy na poprzednim polu atakujacego
    COORDINATES starecoor = ObliczStareCoor(atakujacy, dir);
    swiat->SetPole(starecoor, new Trawa(swiat, starecoor, 0));
    
    //aktualne pole zajmowane przez atakujacego
    swiat->SetPole(pozycja, atakujacy);
}

void Organizm::ObroncaWygral(Zwierze * atakujacy, DIRECTION dir) {
    cout << "    " << GetZnak() << " DEF wygral\n";

    COORDINATES coor = ObliczStareCoor(atakujacy, dir);
    delete atakujacy;

    swiat->SetPole(coor,new Trawa(swiat,coor,0)); // na polu z ktorego ruszyl sie atakujacy ustawiana jest trawa
}

COORDINATES Organizm::ObliczStareCoor(Zwierze* atakujacy, DIRECTION dir) {
    COORDINATES coor = atakujacy->GetPozycja();
    int atakStep = atakujacy->GetStep();

    switch (dir) {
        case UP: {
            coor.y += atakStep;
        }break;
        case DOWN: {
            coor.y -= atakStep;
        }break;
        case LEFT: {
            coor.x += atakStep;
        }break;
        case RIGHT: {
            coor.x -= atakStep;
        }break;
    }
    return coor;
}