#pragma once
#include "Zwierze.h"

class Wilk : public Zwierze {

public:
	Wilk();
	Wilk(Swiat* swiat, COORDINATES coor, int wiek);

	~Wilk();
};
