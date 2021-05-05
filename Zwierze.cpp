#include "Zwierze.h"
#include "Swiat.h"

Zwierze::Zwierze(){}
Zwierze::~Zwierze(){}

int Zwierze::GetStep(){
    return step;
}

void Zwierze::Akcja() {
    DIRECTION dir = ZrobRuch();

    if (dir != NO_CHANGE)
        CzyOdbilAtak(dir);
}

DIRECTION Zwierze::ZrobRuch() {
    DIRECTION dir = NO_CHANGE;
    int proby = 0;
    while (dir == NO_CHANGE) {
        int random = rand() % 3;

        if (proby < 10) proby++;
        else break;

        switch (random) {
            case UP: {
                if (pozycja.y - step >= 0) {
                    cout << "Up" << endl;//key up
                    pozycja.y -= step;
                    dir = UP;
                }
            }break;
            case DOWN: {
                if (pozycja.y + step < swiat->GetWysokosc()) {
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
                if (pozycja.x + step < swiat->GetSzerokosc()) {
                    cout << "Right" << endl;  // key right
                    pozycja.x += step;
                    dir = RIGHT;
                }
            }break;
        }
    }

    if (dir != NO_CHANGE)
        cout << "nowa pozycja zwierzecia " << znak << ": " << pozycja.x << " " << pozycja.y << endl;
    else
        cout << "pozycja zwierzecia nie zmienila sie" << endl;

    return dir;
}

void Zwierze::NastapiloOdbicie(DIRECTION dir) {
    cout << "Odbicie!" << endl;
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
    cout << "powrot na pozycje " << pozycja.x << " " << pozycja.y << endl;
}

void Zwierze::CzyOdbilAtak(DIRECTION dir) {

    Zwierze* Def = (Zwierze*)swiat->GetPole(pozycja);
    Zwierze* Att = this;

    if (Def->GetZnak() == Att->GetZnak()) {
        cout << "ten sam gatunek stoi na tym polu\n";
        RozmazanieZwierzat(Def,dir);
    }
    else {
        // jesli organizm ma sile mniejsza niz 5 --> zolw odeprze jego atak
        if (sila < SILA_GRANICZNA_PRZY_ODBICIU && Def->GetZnak() == ZOLW) {
            NastapiloOdbicie(dir);
        }
        else {
            cout << "Kolizja Att=" << Att->GetZnak() << " z Def=" << Def->GetZnak() << " ";
            Def->Kolizja(Att, dir);
        }
    }

}

void Zwierze::RozmazanieZwierzat(Zwierze* Obronca, DIRECTION dir) {
    NastapiloOdbicie(dir);
    Zwierze* Att = this;

    bool CzyUdaloSieRozmnozyc = false;

    CzyUdaloSieRozmnozyc = ZnajdzPoleDoRozmnazania(Att, Obronca);
    if(!CzyUdaloSieRozmnozyc) ZnajdzPoleDoRozmnazania(Obronca, Att);

    if (!CzyUdaloSieRozmnozyc) cout << "Zwierze " << znak << " nie rozmnozylo sie" << endl;
}


bool Zwierze::ZnajdzPoleDoRozmnazania(Zwierze* org1, Zwierze* org2) {
    bool rozmozone = false;
    COORDINATES pozycja = org1->GetPozycja();
    COORDINATES pozycja2 = org2->GetPozycja();
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            int Xpos = pozycja.x - 1 + j;
            int Ypos = pozycja.y - 1 + i;
            COORDINATES coor{ Xpos, Ypos };
            // cout << " X= " << Xpos << " Y= " << Ypos << endl;
            if (
                coor.x < swiat->GetSzerokosc() && coor.y < swiat->GetWysokosc() &&
                coor.x >= 0 && coor.y >= 0 &&
                !(coor.x == pozycja.x && coor.y == pozycja.y) && 
                !(coor.x == pozycja2.x && coor.y == pozycja2.y)
                )
                rozmozone = Rozmnazaj(coor);

            if (rozmozone == true) {
                cout << "koniec rozmazania " << endl;
                return rozmozone;
            }
        }
    }
    
    return rozmozone;
}


bool Zwierze::Rozmnazaj(COORDINATES coor) {

    if (swiat->GetPole(coor)->GetZnak() == TRAWA) {
        cout << "\n gatunek " << znak << " rozmnozyl sie na polu " << coor.x << " " << coor.y << endl;;

        switch (znak) {
        case ANTYLOPA: {
            swiat->SetPole(coor, new Antylopa(swiat, coor, 0));
        }break;
        case LIS: {
            swiat->SetPole(coor, new Lis(swiat, coor, 0));
        }break;
        case OWCA: {
            swiat->SetPole(coor, new Owca(swiat, coor, 0));
        }break;
        case WILK: {
            swiat->SetPole(coor, new Wilk(swiat, coor, 0));
        }break;
        case ZOLW: {
            swiat->SetPole(coor, new Zolw(swiat, coor, 0));
        }break;
        }
        return true;
    }
    return false;
}