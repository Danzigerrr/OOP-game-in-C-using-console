#include "R_BarszczSosnowskiego.h"



BarszczSosnowskiego::BarszczSosnowskiego() {
	this->sila = 10;
	this->znak = BARSZCZ;
}
BarszczSosnowskiego::BarszczSosnowskiego(Swiat* swiat, const COORDINATES pos, int wiek) {
	this->wiek = wiek;
	this->sila = 10;
	this->znak = BARSZCZ;
	this->swiat = swiat;
	this->pozycja = pos;
}

BarszczSosnowskiego::~BarszczSosnowskiego() {}


void BarszczSosnowskiego::Kolizja(Organizm* org) {
	
	org->~Organizm();
	//Swiat *act = org->GetSwiat();

}

void BarszczSosnowskiego::Akcja() {

}
