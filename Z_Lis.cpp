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
    while (dir == NO_CHANGE) {
        int random = rand() % 3;
        switch (random) {
            if (SprawdzoneMozliwosci < 4) SprawdzoneMozliwosci++;
            else return NO_CHANGE; //jesli nie ma gdzie sie ruszyc, lis zostaje w miejscu

            COORDINATES coor = pozycja;
             // lis nigdy nie ruszy sie na ple zajmowae prez organizm silniejszy niz on
            case UP: {
                if (pozycja.y - step >= 0){
                    coor.y -= step;
                    if (swiat->GetPole(coor)->GetSila() < sila) {
                        cout << "Up" << endl;
                        pozycja = coor;
                        dir = UP;
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
                }
            }break;
            case RIGHT: {
                if (pozycja.x + step < swiat->GetSzerokosc()) 
                    coor.x += step;
                    if (swiat->GetPole(coor)->GetSila() < sila) {
                    cout << "Right" << endl; 
                    pozycja = coor;
                    dir = RIGHT;
                }
            }break;
        }
    }
    return dir;
}
