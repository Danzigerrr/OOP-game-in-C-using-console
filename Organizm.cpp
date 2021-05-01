#include "Organizm.h"
#include "Swiat.h"

Organizm::Organizm(){}

Organizm::~Organizm(){}


bool cmp(Organizm* o1, Organizm* o2) {
    if (o1->GetInicjatywa() != o2->GetInicjatywa()) {
        return o1->GetInicjatywa() < o2->GetInicjatywa();
    }
    return o1->GetWiek() < o2->GetWiek();
}

const char Organizm::GetZnak() {
    return znak;
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

DIRECTION Organizm::ZrobRuch() {
    DIRECTION dir = NO_CHANGE;
    while (dir == NO_CHANGE) {
        int random = rand() % 3;
        switch (random) {
            case UP: {
                if (pozycja.y - step >= 0) {
                    cout << "Up" << endl;//key up
                    pozycja.y -= step;
                    dir = UP;
                }
            }break;
            case DOWN: {
                if (pozycja.y + step <= swiat->GetWysokosc()) {
                    cout << "Down" << endl;  // key down
                    pozycja.y += step;
                    dir = DOWN;
                }
            }break;
            case LEFT: {
                if (pozycja.x - step >= 0) {
                    cout << "Left" << endl;  // key left
                    pozycja.x -= step;
                    dir = LEFT;
                }
            }break;
            case RIGHT: {
                if (pozycja.x + step <= swiat->GetSzerokosc()) {
                    cout << "Right" << endl;  // key right
                    pozycja.x += step;
                    dir = RIGHT;
                }
            }break;
        }
    }
    return dir;
}


void Organizm::SprawdzKolizje(DIRECTION dir) {

    if (dir != NO_CHANGE) {

        Organizm* Def = swiat->GetPlansza()[pozycja.y][pozycja.x];

        if (sila < 5 && Def->GetZnak() == 'Z') // jesli organizm ma sile <5 --> zolw odeprze jego atak
        {
            switch (dir) { // organizm sie cofa
                case UP: {
                    pozycja.y += step;
                }break;
                case DOWN: {
                    pozycja.y -= step;
                }break;
                case LEFT: {
                    pozycja.x += step;
                }break;
                case RIGHT: {
                    pozycja.x -= step;
                }break;
            }
        }
        else {
            cout << "Kolizja Att=" << this->GetZnak() << " z Def=" << Def->GetZnak() << " ";
            Def->Kolizja(this);
        }
    }
    
}