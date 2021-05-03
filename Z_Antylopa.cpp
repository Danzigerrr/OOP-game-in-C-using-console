#include "Z_Antylopa.h"
#include "Swiat.h"
#define ZASIEG_UCIECZKI 1
Antylopa::Antylopa() {
    init();
}
Antylopa::Antylopa(Swiat* swiat, const COORDINATES pos, int wiek) {
    init();
	this->wiek = wiek;
	this->swiat = swiat;
	this->pozycja = pos;
}

void Antylopa::init() {
    this->sila = 4;
    this->inicjatywa = 4;
    this->step = 2;
    this->znak = ANTYLOPA;
}

Antylopa::~Antylopa() {}

bool Antylopa::ucieka(Zwierze* atakujacy, COORDINATES coor, DIRECTION dir) {
    if (swiat->GetPole(coor)->GetZnak() == TRAWA) {
        cout << "\n antylopa " << znak << " ma mozliwosc ucieczki na pole " << coor.x << " " << coor.y << endl;
        COORDINATES staraPozAntylopy = pozycja;

        //nowe pole antylopy
        pozycja = coor;
        swiat->SetPole(coor, this);

        COORDINATES staraPozAtakujacego = ObliczStareCoor(atakujacy, dir);
        cout << "na starym polu atakujacego " << staraPozAtakujacego.x << " " << staraPozAtakujacego.y << " pojawia sie trawa \n";
        swiat->SetPole(staraPozAtakujacego, new Trawa(swiat, staraPozAtakujacego, 0));

        cout << " " << atakujacy->GetZnak() << "zajmuje pole kiedys zajmowane przez antylope ";
        //aktualne pole zajmowane przez atakujacego
        atakujacy->SetPozycja(staraPozAntylopy);
        swiat->SetPole(staraPozAntylopy, atakujacy);

        return true;
    }
    return false;
}

void Antylopa::Kolizja(Zwierze* atakujacy, DIRECTION dir)
{
    bool AntylopaUcieka = rand() % 1;

    if (AntylopaUcieka) {
        bool uciekla = false;
        while (uciekla == false) {
            for (int i = 0; i <= 2 * ZASIEG_UCIECZKI; i++) {
                for (int j = 0; j <= 2 * ZASIEG_UCIECZKI; j++) {
                    int Xpos = pozycja.x - ZASIEG_UCIECZKI + j;
                    int Ypos = pozycja.y - ZASIEG_UCIECZKI + i;
                    COORDINATES coor{ Xpos, Ypos };
                    // cout << " X= " << Xpos << " Y= " << Ypos << endl;
                    if (
                        coor.x < swiat->GetSzerokosc() && coor.y < swiat->GetWysokosc() &&
                        coor.x >= 0 && coor.y >= 0 &&
                        !(coor.x == pozycja.x && coor.y == pozycja.y)
                        )
                        uciekla = ucieka(atakujacy,coor, dir);

                    if (uciekla == true) {
                        cout << "antylopa ucieczkla na pole " << pozycja.x << " " << pozycja.y << endl;
                        j = 2 * ZASIEG_UCIECZKI;
                        i = 2 * ZASIEG_UCIECZKI;
                    }
                }
            }
        }

    }

    else { 
        NormalnaKolizja(atakujacy, dir);
    }
}

