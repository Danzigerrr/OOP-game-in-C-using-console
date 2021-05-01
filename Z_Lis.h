#pragma once
#include "Zwierze.h"

class Lis : public Zwierze {


public:
	Lis();
	Lis(Swiat* swiat, COORDINATES pos, int wiek);

	DIRECTION ZrobRuch() override;

	~Lis();
};