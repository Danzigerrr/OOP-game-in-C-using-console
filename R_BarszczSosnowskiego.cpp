#include "R_BarszczSosnowskiego.h"



BarszczSosnowskiego::BarszczSosnowskiego() {}
BarszczSosnowskiego::BarszczSosnowskiego(Swiat* swiat, const COORDINATES pos, int wiek) {
	this->wiek = wiek;
	this->sila = 10;
	this->swiat = swiat;
	this->pozycja = pos;
}

BarszczSosnowskiego::~BarszczSosnowskiego() {}

const char BarszczSosnowskiego::GetZnak() { return BARSZCZ; }
void BarszczSosnowskiego::Kolizja(Organizm* org) {
	
	org->~Organizm();
	//Swiat *act = org->GetSwiat();

}

void BarszczSosnowskiego::Akcja() {

}
