#pragma once
#include "Zwierze.h"
#include "Swiat.h"
class Antylopa : public Zwierze {
private:
	void init() override;
public:
	Antylopa();
	Antylopa(Swiat* swiat, COORDINATES coor, int wiek);

	void Kolizja(Zwierze* atakujacy, DIRECTION dir) override;

	~Antylopa();
};
