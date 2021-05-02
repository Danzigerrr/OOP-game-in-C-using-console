#pragma once
#include "Roslina.h"

class Trawa : public Roslina {
private:
	void init() override;
public:
	Trawa();
	Trawa(Swiat* swiat, const COORDINATES pos, int wiek);
	~Trawa();


};
