#include "Z_Zolw.h"
#include "Swiat.h"
Zolw::Zolw() {
	init();
}
Zolw::Zolw(Swiat* swiat, const COORDINATES pos, int wiek) {
	init();
	this->wiek = wiek;
	this->swiat = swiat;
	this->pozycja = pos;
}

Zolw::~Zolw() {}


void Zolw::Akcja() {
	int SzansaNaRuch = rand() % 3; // w 75% zolw nie zmienia swojego polozenia
	if (SzansaNaRuch) {
		DIRECTION dir = ZrobRuch();
		CzyOdbilAtak(dir);
	}
}

void Zolw::Kolizja(Organizm* atakujacy) {
    COORDINATES coor = pozycja;
    Organizm* Org = NULL;
    char gatunek = GetZnak();
    switch (gatunek) {
    case ANTYLOPA: { Org = new Antylopa(swiat, coor, wiek); }break;
    case LIS: { Org = new Lis(swiat, coor, wiek); }break;
    case OWCA: { Org = new Owca(swiat, coor, wiek); }break;
    case WILK: {  Org = new Wilk(swiat, coor, wiek); }break;
    case ZOLW: { Org = new Zolw(swiat, coor, wiek); }break;
    case BARSZCZ: { Org = new BarszczSosnowskiego(swiat, coor, wiek); }break;
    case GUARANA: { Org = new Guarana(swiat, coor, wiek); }break;
    case MLECZ: { Org = new Mlecz(swiat, coor, wiek); }break;
    case TRAWA: { Org = new Trawa(swiat, coor, wiek); }break;
    case WILCZEJAGODY: { Org = new WilczeJagody(swiat, coor, wiek); }break;
    case CZLOWIEK: { Org = new Czlowiek(swiat, coor, wiek); }break;
    }

    swiat->SetPole(pozycja, Org);

}


void Zolw::init() {
	this->sila = 2;
	this->inicjatywa = 1;
	this->znak = ZOLW;
}