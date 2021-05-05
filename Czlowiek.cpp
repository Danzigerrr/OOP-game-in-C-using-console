#include "Czlowiek.h"
#include "Swiat.h"
Czlowiek::Czlowiek() {
    init();
}
Czlowiek::Czlowiek(Swiat* swiat, const COORDINATES pos, int wiek) {
    init();
	this->wiek = wiek;
	this->swiat = swiat;
	this->pozycja = pos;
}

void Czlowiek::init() {
    this->znak = CZLOWIEK;
    this->sila = 5;
    this->inicjatywa = 4;
}

int Czlowiek::GetUmiejetnoscAktywnaPrzez() {
    return UmiejAktywnaPrzez;
}

int Czlowiek::GetUmiejetnoscOdnawianaPrzez() {
    return UmiejOdnawianaPrzez;
}

Czlowiek::~Czlowiek() {}

void Czlowiek::SetUmiejetnoscAktywnaPrzez(int value) {
    UmiejAktywnaPrzez = value;
}
void Czlowiek::SetUmiejetnoscOdnawianaPrzez(int value) {
    UmiejOdnawianaPrzez = value;
}
void Czlowiek::SetKierunekRuchuCzlowieka(int value) {
    KierunekRuchuCzlowieka = value;
}

DIRECTION Czlowiek::ZrobRuch() {

    DIRECTION dir = NO_CHANGE;
    switch (KierunekRuchuCzlowieka) {
    case KEY_UP: {
        cout << "Up" << endl;
        if (pozycja.y > 0) {
            pozycja.y--;
            dir = UP;
        }
    }break;
    case KEY_DOWN: {
        cout << "Down" << endl;
        if (pozycja.y < swiat->GetWysokosc() - 1) {

            pozycja.y++;
            dir = DOWN;
        }
    }break;
    case KEY_LEFT: {
        cout << "Left" << endl;
        if (pozycja.x > 0) {
            pozycja.x--;
            dir = LEFT;
        }
    }break;
    case KEY_RIGHT: {
        cout << "Right" << endl;
        if (pozycja.x < swiat->GetSzerokosc() - 1) {
            pozycja.x++;
            dir = RIGHT;
        }
    }break;
    default:
        if (UmiejAktywnaPrzez == 5)
            cout << "W tym ruchu zostala uruchomiona Tarcza Alzura\n";
        else
            cout << "Wcisnales zly klawisz\n";
        break;
    }


    cout << "nowa pozycja: ";
    if (dir == NO_CHANGE) 
        cout << "NO change" << endl;
    else 
        cout << pozycja.x << " " << pozycja.y << endl;
    

    return dir;
}

void Czlowiek::Akcja() {

    DIRECTION dir = ZrobRuch();

    if(dir != NO_CHANGE)
    CzyOdbilAtak(dir);

    if (UmiejAktywnaPrzez > 0 || UmiejOdnawianaPrzez > 0) {
        if (UmiejAktywnaPrzez > 0)
            UmiejAktywnaPrzez--;

        if (UmiejAktywnaPrzez == 0 && UmiejOdnawianaPrzez == 0)
            UmiejOdnawianaPrzez = UMIEJETNOSC_ODNAWIANA;
        else if (UmiejOdnawianaPrzez > 0) 
            UmiejOdnawianaPrzez--; 
    }
   
}

void Czlowiek::KolizjaZAktywnaUmiejetnoscia(Zwierze* atakujacy, DIRECTION dir) {
    bool RuchMozliwy = false;
    COORDINATES starecoor = ObliczStareCoor(atakujacy, dir);
    COORDINATES noweCoorAtakujacego = pozycja;
    int atakstep = atakujacy->GetStep();
    int i = 0;
    while (i < 4 || RuchMozliwy == false) {
        switch (i) {
            case UP: {
                if (pozycja.y > 0) {
                    noweCoorAtakujacego.y--;
                    RuchMozliwy = true;
                }
            }break;
            case DOWN: {
                if (pozycja.y < swiat->GetWysokosc() - 1) {
                    noweCoorAtakujacego.y++;
                    RuchMozliwy = true;
                }
            }break;
            case LEFT: {
                if (pozycja.x > 0) {
                    noweCoorAtakujacego.x--;
                    RuchMozliwy = true;
                }
            }break;
            case RIGHT: {
                if (pozycja.x < swiat->GetSzerokosc() - 1) {
                    noweCoorAtakujacego.x++;
                    RuchMozliwy = true;
                }
            }break;
        }
        i++;
    }

    if (RuchMozliwy == false) {
        cout << "Atakujacy nie ma sie gdzie ruszyc, " << atakujacy->GetZnak() << " ginie" << endl;
        ObroncaWygral(atakujacy, dir);
    }

    else {
        cout << "SPECJALNA UMIEJETNOSC DALA O SOBIE ZNAK - TARCZA ALZURA ZADZIALALA! HURRA!!!\n";
        cout << atakujacy->GetZnak() << " zostal przesuniety na pole " << noweCoorAtakujacego.x << " " << noweCoorAtakujacego.y << endl;
        atakujacy->SetPozycja(noweCoorAtakujacego);
        swiat->SetPole(noweCoorAtakujacego, atakujacy);

        if (!(starecoor.x == noweCoorAtakujacego.x && starecoor.y == noweCoorAtakujacego.y)) {
            cout << "Atakujacy zajal nowe pole (inne od poprzedniego), wiec na starym polu atakujacego ustawiana jest trawa" << endl;
            swiat->SetPole(starecoor, new Trawa(swiat, starecoor, 0));
        }
    }
}

void Czlowiek::Kolizja(Zwierze* atakujacy, DIRECTION dir) {

    if (UmiejAktywnaPrzez > 0)
        KolizjaZAktywnaUmiejetnoscia(atakujacy, dir);
    else 
        NormalnaKolizja(atakujacy, dir);
       
}

