#include "Organizm.h"
#include "Swiat.h"

Organizm::Organizm(){}
Organizm::~Organizm(){}

const char Organizm::GetZnak() {
    return znak;
}
int Organizm::GetSila() {
    return this->sila;
}
void Organizm::SetSila(int sila) {
    this->sila = sila;
}
int Organizm::GetInicjatywa() {
    return this->inicjatywa;
}
void Organizm::SetInicjatywa(int inicjatywa) {
    this->inicjatywa = inicjatywa;
}
COORDINATES Organizm::GetPozycja() {
    return this->pozycja;
}
void Organizm::SetPozycja(COORDINATES pos) {
    this->pozycja = pos;
}
int Organizm::GetWiek() {
    return this->wiek;
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

void Organizm::Kolizja(Organizm* atakujacy) {
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
            delete this;
        }
    }

    else //jesli sily sa rowne --> wygrywa atakujacy
    {
        cout << atakujacy->GetZnak() << " wygral\n";
        delete this;
    }
}
