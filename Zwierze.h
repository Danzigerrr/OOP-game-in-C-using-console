#pragma once
#include "Organizm.h"

class Zwierze : public Organizm {
protected:

	void CzyOdbilAtak(DIRECTION dir);
	void NastapiloOdbicie(DIRECTION dir);
	virtual DIRECTION ZrobRuch();
	int step = 1;
public:
	Zwierze();
	~Zwierze();
	int GetStep();

	virtual void Akcja() override;

};
