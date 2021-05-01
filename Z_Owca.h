#pragma once
#include "Zwierze.h"

class Owca : public Zwierze {

public:
	Owca();
	Owca(Swiat* swiat, COORDINATES pos, int wiek);

	~Owca();
};