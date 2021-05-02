#pragma once
#include "Zwierze.h"

class Owca : public Zwierze {
private:
	void init() override;
public:
	Owca();
	Owca(Swiat* swiat, COORDINATES pos, int wiek) : Owca() {};
	~Owca();
	
	/*	explenation:														   
	https://stackoverflow.com/questions/14183939/c-constructor-call-another-constructor-based-on-parameter-type 

	*/
};