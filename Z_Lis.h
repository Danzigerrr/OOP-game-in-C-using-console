#pragma once
#include "Zwierze.h"

class Lis : public Zwierze {
private:
	void init() override;
	DIRECTION ZrobRuch() override;

public:
	Lis();
	Lis(Swiat* swiat, COORDINATES pos, int wiek);


	~Lis();
};