#pragma once
#include "Organizm.h"

class Zwierze : public Organizm {
protected:

	void CzyOdbilAtak(DIRECTION dir);
	void NastapiloOdbicie(DIRECTION dir);
	void RozmazanieZwierzat(Zwierze* atakujacy, DIRECTION dir);
	bool ZnajdzPoleDoRozmnazania(Zwierze* org1, Zwierze* org2);
	bool Rozmnazaj(COORDINATES coor);
	virtual DIRECTION ZrobRuch();
	int step = 1;
public:
	Zwierze();
	~Zwierze();
	int GetStep();

	virtual void Akcja() override;

};
