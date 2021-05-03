#pragma once
#include "Organizm.h"

class Roslina : public Organizm {
private:
	int inicjatywa = 0;
protected:
	void NormalnaAkcjaRoslin();
	virtual void init() = 0;
	bool Split(COORDINATES coor);
	bool ObliczSzanseNaRozsianie();
	void ZbadajSasiadow();
	//Organizm* nastepny(const DIRECTION kierunek, const int distnace);
	void ZabijAtakujacego(Zwierze* atakujacy, DIRECTION dir);
public:
	Roslina(); 
	~Roslina();

	virtual void Akcja() override;
};
