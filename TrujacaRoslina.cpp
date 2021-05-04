#include "TrujacaRoslina.h"
#include "Swiat.h"
void TrujacaRoslina::ZabijAtakujacego(Zwierze* atakujacy, DIRECTION dir) {
    cout << atakujacy->GetZnak() << " wygral\n orgnaizm zabija atakujacego\n";
    delete atakujacy;
    swiat->SetPole(pozycja, new Trawa(swiat, pozycja, 0));
    /*COORDINATES coor = pozycja;
    Swiat* s = swiat;
    delete this;
    s->SetPole(coor, new Trawa(s, coor, 0));*/

}

