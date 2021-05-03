#pragma once
#include "Organizm.h"

class Roslina : public Organizm {
private:
	int inicjatywa = 0;
protected:
	void NormalnaAkcjaRoslin();
	virtual void init() = 0;
	void Split();
	bool CzyRozprzestrzeniac();
	//Organizm* nastepny(const DIRECTION kierunek, const int distnace);
public:
	Roslina(); 
	~Roslina();

	virtual void Akcja() override;
};
