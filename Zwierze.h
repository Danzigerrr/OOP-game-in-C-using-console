#pragma once
#include "Organizm.h"

class Zwierze : public Organizm {
protected:
	virtual void init() = 0;
	virtual void CzyOdbilAtak(DIRECTION dir);
	virtual DIRECTION ZrobRuch();
	int step = 1;
public:
	Zwierze();
	~Zwierze();
	int GetStep();

	virtual void Akcja() override;

};
