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
    return UmiejetnoscAktywnaPrzez;
}

int Czlowiek::GetUmiejetnoscOdnawianaPrzez() {
    return UmiejetnoscOdnawianaPrzez;
}

Czlowiek::~Czlowiek() {}

void Czlowiek::SetUmiejetnoscAktywnaPrzez(int value) {
    UmiejetnoscAktywnaPrzez = value;
}
void Czlowiek::SetUmiejetnoscOdnawianaPrzez(int value) {
    UmiejetnoscOdnawianaPrzez = value;
}
void Czlowiek::SetKierunekRuchuCzlowieka(int value) {
    KierunekRuchuCzlowieka = value;

    switch (KierunekRuchuCzlowieka) {
    case KEY_UP: {
        cout << "Up" << endl;//key up

    }break;
    case KEY_DOWN: {
        cout << "Down" << endl;  // key down

    }break;
    case KEY_LEFT: {
        cout << "Left" << endl;  // key left

    }break;
    case KEY_RIGHT: {
        cout << "Right" << endl;  // key right

    }break;
    default:
        cout << "Incorrect key input" << endl;  // not arrow
        break;
    }
}

void Czlowiek::Akcja() {
    cout << "Czlowiek rusza sie: ";
    DIRECTION dir = NO_CHANGE;
    switch (KierunekRuchuCzlowieka) {
        case KEY_UP: {
            cout << "Up" << endl;//key up
            if (pozycja.y > 0) {
                pozycja.y--;
                dir = UP;
            }
        }break;
        case KEY_DOWN: {
            cout << "Down" << endl;  // key down
            if (pozycja.y < swiat->GetWysokosc()) {
                pozycja.y++;
                dir = DOWN;
            }
        }break;
        case KEY_LEFT: {
            cout << "Left" << endl;  // key left
            if (pozycja.x > 0) {
                pozycja.x--;
                dir = LEFT;
            }
        }break;
        case KEY_RIGHT: {
            cout << "Right" << endl;  // key right
            if (pozycja.x < swiat->GetSzerokosc()){
                pozycja.x++;
               
                dir = RIGHT;
            }
        }break;
        default:
            cout << "Incorrect key input" << endl;  // not arrow
            break;
    }

    cout << "nowa pozycja: " << pozycja.x << " " << pozycja.y << endl;

    if (UmiejetnoscAktywnaPrzez > 0) {cout << "Specjalna umiejetnosc aktywna przez: " << UmiejetnoscAktywnaPrzez << endl;}
    if (UmiejetnoscOdnawianaPrzez > 0) {cout << "Specjalna umiejetnosc odnawiana przez: " << UmiejetnoscOdnawianaPrzez << endl;}

    CzyOdbilAtak(dir);

    if (UmiejetnoscAktywnaPrzez > 0 || UmiejetnoscOdnawianaPrzez > 0) {
        if (UmiejetnoscAktywnaPrzez > 0) { UmiejetnoscAktywnaPrzez--; }

        if (UmiejetnoscAktywnaPrzez == 0 && UmiejetnoscOdnawianaPrzez == 0) UmiejetnoscOdnawianaPrzez = UMIEJETNOSC_ODNAWIANA;
        else if (UmiejetnoscOdnawianaPrzez > 0) { UmiejetnoscOdnawianaPrzez--; }
    }
}



void Czlowiek::Kolizja(Organizm* atakujacy) {

    //Specjalna umiejetnosc --> Człowiek odstrasza wszystkie zwierzęta.
    //Zwierzę które stanie na polu Człowieka zostaje przesunięte na losowe pole sąsiednie.
    if (UmiejetnoscAktywnaPrzez > 0)
    {
        bool RuchMozliwy = false;
        COORDINATES poz_atak = atakujacy->GetPozycja();
        while (RuchMozliwy == false) {
             switch (rand() % 3) {
                case UP: {
                    if (poz_atak.y > 0) {
                        pozycja.y--;
                        RuchMozliwy = true;
                    }
                }break;
                case DOWN: {
                    if (pozycja.y < swiat->GetWysokosc()){
                        pozycja.y++;
                        RuchMozliwy = true;
                    }
                }break;
                case LEFT: {
                    if (pozycja.x > 0){
                        pozycja.x--;
                        RuchMozliwy = true;
                    }
                }break;
                case RIGHT: {
                    if (pozycja.x < swiat->GetSzerokosc()){
                        pozycja.x++;
                        RuchMozliwy = true;
                    }
                }break;
            }
        }

        atakujacy->SetPozycja(poz_atak);

        vector<Organizm*> w = swiat->wezWszystkieOrganizmy();
        for (auto o_ptr : w) {
            COORDINATES coor = o_ptr->GetPozycja();

            if (coor.x == pozycja.x && coor.y == pozycja.y) {
                cout << "Kolizja " << atakujacy->GetZnak() << " z " << o_ptr->GetZnak() << endl;
                o_ptr->Kolizja(atakujacy);
                break;
            }
        }
    }


    else //normalna kolizja
    {
        NormalnaKolizja(atakujacy);
        
    }
}

