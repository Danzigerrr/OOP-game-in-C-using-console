#include "TrujacaRoslina.h"
#include "Swiat.h"
void TrujacaRoslina::ZabijAtakujacego(Zwierze* atakujacy, DIRECTION dir) {
    cout << atakujacy->GetZnak() << " wygral, ale ten orgnaizm jest roslina trujaca i zabija atakujacego\n";
    delete atakujacy;
    swiat->SetPole(pozycja, new Trawa(swiat, pozycja, 0));

}

