#pragma once
#include "Zwierze.h"

class Owca : public Zwierze {
private:
	void init() override;
public:
	Owca();
	Owca(Swiat* swiat, COORDINATES pos, int wiek);
	~Owca();
	
	
};