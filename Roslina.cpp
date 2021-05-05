#include "Roslina.h"
#include "Swiat.h"
#define ZASIEG_ROZSIEWU_POZIOM 1
#define ZASIEG_ROZSIEWU_PION 1

Roslina::Roslina(){}
Roslina::~Roslina() {}

void Roslina::Akcja() {
    NormalnaAkcjaRoslin();
}
void Roslina::NormalnaAkcjaRoslin() {
    if (ObliczSzanseNaRozsianie())
        ZbadajSasiadow();
}
bool Roslina::ObliczSzanseNaRozsianie() {
	int szansa = rand() % 100;
	if (szansa < SZANSA_NA_ROZSIEW)
        return true;
	else
        return false;
}

void Roslina::ZbadajSasiadow() {
    bool rozsiana = false;
    while (rozsiana == false) {
        for (int i = 0; i <= 2 * ZASIEG_ROZSIEWU_PION; i++) {
            for (int j = 0; j <= 2 * ZASIEG_ROZSIEWU_POZIOM; j++) {
                int Xpos = pozycja.x - ZASIEG_ROZSIEWU_POZIOM  + j ;
                int Ypos = pozycja.y - ZASIEG_ROZSIEWU_PION  + i ;
                COORDINATES coor{ Xpos, Ypos };
               // cout << " X= " << Xpos << " Y= " << Ypos << endl;
                if (
                    coor.x < swiat->GetSzerokosc() && coor.y < swiat->GetWysokosc() &&
                    coor.x >= 0 && coor.y >= 0 &&
                    !(coor.x == pozycja.x && coor.y == pozycja.y)
                    )
                    rozsiana = Split(coor);
                if (rozsiana == true) {
                    i = 2 * ZASIEG_ROZSIEWU_PION;
                    j = 2 * ZASIEG_ROZSIEWU_POZIOM;
                    break;
                }
            }

            if (i == 2 || rozsiana == true) {
                i = 2 * ZASIEG_ROZSIEWU_PION;
                rozsiana = true;
                break;
            }
        }
    }
}

bool Roslina::Split(COORDINATES coor) {

    if (swiat->GetPole(coor)->GetZnak() == TRAWA) {
        if(GetZnak() != TRAWA)//dla trawy nie infromuj o rozsianiu
        cout << "\n gatunek " << znak << " rozsial sie na polu " << coor.x << " " << coor.y << endl;;
        switch (znak) {
            case TRAWA: {
                swiat->SetPole(coor, new Trawa(swiat, coor, 0));
            }break;
            case MLECZ: {
                swiat->SetPole(coor, new Mlecz(swiat, coor, 0));
            }break;
            case GUARANA: {
                swiat->SetPole(coor, new Guarana(swiat, coor, 0));
            }break;
            case WILCZEJAGODY: {
                swiat->SetPole(coor, new WilczeJagody(swiat, coor, 0));
            }break;
            case BARSZCZ: {
                swiat->SetPole(coor, new BarszczSosnowskiego(swiat, coor, 0));
            }break;
        }
        return true;
    }
    return false;
}
