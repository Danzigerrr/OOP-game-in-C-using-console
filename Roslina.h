#pragma once
#include "Organizm.h"

class Roslina : public Organizm {
protected:
	const int inicjatywa = 0;
	void NormalnaAkcjaRoslin();
	bool Split(COORDINATES coor);
	bool ObliczSzanseNaRozsianie();
	void ZbadajSasiadow();

public:
	Roslina(); 
	~Roslina();

	virtual void Akcja() override;
};
