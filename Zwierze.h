#pragma once
#include "Organizm.h"

class Zwierze : public Organizm {
protected:
	virtual void init() = 0;
	virtual void SprawdzKolizje(DIRECTION dir);
	virtual DIRECTION ZrobRuch();
	int step = 1;
public:
	Zwierze();
	~Zwierze();

	virtual void Akcja() override;

};
