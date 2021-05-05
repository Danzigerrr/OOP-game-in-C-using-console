#include "Z_Lis.h"
#include "Swiat.h"

Lis::Lis() {
    init();
}
Lis::Lis(Swiat* swiat, const COORDINATES pos, int wiek) {
    init();
	this->wiek = wiek;
	this->swiat = swiat;
	this->pozycja = pos;
}

void Lis::init() {
    this->sila = 3;
    this->inicjatywa = 7;
    this->znak = LIS;
}

Lis::~Lis() {}




DIRECTION Lis::ZrobRuch() {
    DIRECTION dir = NO_CHANGE;
    int SprawdzoneMozliwosci = 0;
    bool KoloLisaJestSilniejszyOrg = false;

    while (dir == NO_CHANGE) {
        COORDINATES coor = pozycja;
        int random = rand() % 4;
        if (SprawdzoneMozliwosci < ILOSC_PROB_LOSOWYCH_RUCHOW) SprawdzoneMozliwosci++;
        else break; //jesli nie ma gdzie sie ruszyc, lis zostaje w miejscu

        switch (random) {    
             // lis nigdy nie ruszy sie na ple zajmowae prez organizm silniejszy niz on
            case UP: {
                if (pozycja.y - step >= 0){
                    coor.y -= step;
                    if (swiat->GetPole(coor)->GetSila() < sila) {
                        cout << "Up" << endl;
                        pozycja = coor;
                        dir = UP;
                    }
                    else {
                        KoloLisaJestSilniejszyOrg = true;
                        coor = pozycja;
                    }
                }
            }break;
            case DOWN: {
                if (pozycja.y + step < swiat->GetWysokosc()) {
                    coor.y += step;
                    if (swiat->GetPole(coor)->GetSila() < sila) {
                        cout << "Down" << endl; 
                        pozycja = coor;
                        dir = DOWN;
                    }
                    else {
                        KoloLisaJestSilniejszyOrg = true;
                        coor = pozycja;
                    }
                }
            }break;
            case LEFT: {
                if (pozycja.x - step >= 0) {
                    coor.x -= step;
                    if (swiat->GetPole(coor)->GetSila() < sila) {
                        cout << "Left" << endl;  
                        pozycja = coor;
                        dir = LEFT;
                    }
                    else {
                        KoloLisaJestSilniejszyOrg = true;
                        coor = pozycja;
                    }
                }
            }break;
            case RIGHT: {
                if (pozycja.x + step < swiat->GetSzerokosc()) {
                    coor.x += step;
                    if (swiat->GetPole(coor)->GetSila() < sila) {
                        cout << "Right" << endl;
                        pozycja = coor;
                        dir = RIGHT;
                    }
                    else {
                        KoloLisaJestSilniejszyOrg = true;
                        coor = pozycja;
                    }
                }
            }break;
        }
    }

    if(KoloLisaJestSilniejszyOrg)
        cout << "kolo lisa znajduje sie silniejszy organizm!\n";

    if (dir != NO_CHANGE)
        cout << "nowa pozycja " << GetZnak() << " " << pozycja.x << " " << pozycja.y << endl;
    else
        cout << "pozycja " << GetZnak() << " nie zmienila sie" << endl;

    return dir;
}
