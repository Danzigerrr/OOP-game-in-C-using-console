#pragma once
#include "Zwierze.h"

class Wilk : public Zwierze {
private:
	void init() override;
public:
	Wilk();
	Wilk(Swiat* swiat, COORDINATES coor, int wiek);

	~Wilk();
};
