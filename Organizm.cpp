#include "Organizm.h"

bool cmp(Organizm* o1, Organizm* o2) {
    if (o1->GetInicjatywa() != o2->GetInicjatywa()) {
        return o1->GetInicjatywa() < o2->GetInicjatywa();
    }
    return o1->GetWiek() < o2->GetWiek();
}

void Organizm::nadajSwiat(Swiat* s) {
    swiat = s;
}

void Organizm::nadajPozycje(int x, int y) {   
    pozycja.x = x;
    pozycja.y = y;
}


int Organizm::GetSila() {
    return this->sila;

}

int Organizm::GetInicjatywa() {
    return this->inicjatywa;
}

COORDINATES Organizm::GetPozycja() {
    return this->pozycja;
}

int Organizm::GetWiek() {
    return this->wiek;
}
Swiat* Organizm::GetSwiat() {
    return swiat;
}