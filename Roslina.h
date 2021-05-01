#pragma once
#include "Organizm.h"

class Roslina : public Organizm {
protected:
	virtual void Split() = 0;
	void Kolizja(Organizm* o) override = 0; 
	//Organizm* nastepny(const DIRECTION kierunek, const int distnace);
public:
	Roslina(); 
	virtual void Akcja() override ;


	~Roslina();

};
