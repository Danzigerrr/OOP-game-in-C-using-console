#pragma once
#include "Zwierze.h"

class Antylopa : public Zwierze {
private:
	void init() override;
	bool ucieka(Zwierze* atakujacy, COORDINATES coor, DIRECTION dir);
public:
	Antylopa();
	Antylopa(Swiat* swiat, COORDINATES coor, int wiek);

	void Kolizja(Zwierze* atakujacy, DIRECTION dir) override;

	~Antylopa();
};
