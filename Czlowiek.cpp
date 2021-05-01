#include "Czlowiek.h"
#include "Swiat.h"
Czlowiek::Czlowiek() {}
Czlowiek::Czlowiek(Swiat* swiat, const COORDINATES pos, int wiek) {
	this->wiek = wiek;
	this->sila = 5;
	this->inicjatywa = 4;
	this->swiat = swiat;
	this->pozycja = pos;
}


Czlowiek::~Czlowiek() {}

const char Czlowiek::GetZnak() {
	return CZLOWIEK;
}

void Czlowiek::Akcja() {
    KierunekRuchuCzlowieka = 0;
    int PierwszyChar = _getch(); // podwojny input

    if (PierwszyChar == ESC) exit(1);
    if (PierwszyChar == ENTER && UmiejetnoscAktywnaPrzez == 0 && UmiejetnoscOdnawianaPrzez == 0) {
        cout << "Specjalna umiejetnosc aktywowana";
        UmiejetnoscAktywnaPrzez = ELIKSIR_AKTYWNY;
    }
    else {
        cout << "Czlowiek rusza sie w ";
        switch ((KierunekRuchuCzlowieka = _getch())) {
        case KEY_UP: {
            cout << "Up" << endl;//key up
            if(pozycja.y > 0)
            pozycja.y--;
        }break;
        case KEY_DOWN: {
            cout << "Down" << endl;  // key down
            if (pozycja.y < swiat->GetWysokosc())
                pozycja.y++;
        }break;
        case KEY_LEFT: {
            cout << "Left" << endl;  // key left
            if (pozycja.x > 0)
                pozycja.x--;
        }break;
        case KEY_RIGHT: {
            cout << "Right" << endl;  // key right
            if (pozycja.x < swiat->GetSzerokosc())
                pozycja.x++;
        }break;
        default:
            cout << "Not right key" << endl;  // not arrow
            break;
        }
    }

    if (UmiejetnoscAktywnaPrzez > 0) {cout << "Specjalna umiejetnosc aktywna przez: " << UmiejetnoscAktywnaPrzez << endl;}
    if (UmiejetnoscOdnawianaPrzez > 0) {cout << "Specjalna umiejetnosc odnawiana przez: " << UmiejetnoscOdnawianaPrzez << endl;}

    vector<Organizm*> w = swiat->wezWszystkieOrganizmy();
    for (auto o_ptr : w) {
       COORDINATES coor = o_ptr->GetPozycja();

       if (coor.x == pozycja.x && coor.y == pozycja.y) {
           cout << "Kolizja " << CZLOWIEK << " z " << o_ptr->GetZnak() << endl;
           Kolizja(o_ptr);
       }

    }




    if (UmiejetnoscAktywnaPrzez > 0) {  UmiejetnoscAktywnaPrzez--;  }
    if (UmiejetnoscOdnawianaPrzez > 0) { UmiejetnoscOdnawianaPrzez--; }
}

void Czlowiek::Kolizja(Organizm* o) {

}