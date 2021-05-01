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

void Organizm::SprawdzKolizje() {
    vector<Organizm*> w = swiat->wezWszystkieOrganizmy();
    for (auto o_ptr : w) {
        COORDINATES coor = o_ptr->GetPozycja();

        if (coor.x == pozycja.x && coor.y == pozycja.y) {
            cout << "Kolizja " << this->GetZnak() << " z " << o_ptr->GetZnak() << endl;

            if (sila < 5 && o_ptr->GetZnak() == 'Z') // jesli organizm ma sile <5 --> zolw odeprze jego atak, organizm sie cofa
            {
                switch (KierunekRuchuCzlowieka) {
                case KEY_UP: {
                    pozycja.y++;
                }break;
                case KEY_DOWN: {
                    pozycja.y--;
                }break;
                case KEY_LEFT: {
                    pozycja.x++;
                }break;
                case KEY_RIGHT: {
                    pozycja.x--;
                }break;
                }
            }
            else
                o_ptr->Kolizja(this);

            break;
        }
    }
}