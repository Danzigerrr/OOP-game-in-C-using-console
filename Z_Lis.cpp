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
        COORDINATES coor = pozycja;
        //cout << " START:     " << coor.x << "  " << coor.y << " S= " << step << endl;
        
        if (SprawdzoneMozliwosci < 10) SprawdzoneMozliwosci++;
        else break; //jesli nie ma gdzie sie ruszyc, lis zostaje w miejscu

        switch (random) {    
             // lis nigdy nie ruszy sie na ple zajmowae prez organizm silniejszy niz on
            case UP: {
                if (pozycja.y - step >= 0){
                    coor.y -= step;
                   // cout << " UP     "<< coor.x << "  " << coor.y << endl;
                    if (swiat->GetPole(coor)->GetSila() < sila) {
                        cout << "Up" << endl;
                        pozycja = coor;
                        dir = UP;
                    }
                    else
                        coor = pozycja;
                }
            }break;
            case DOWN: {
                if (pozycja.y + step < swiat->GetWysokosc()) {
                    coor.y += step;
                   // cout << " DOWN    " << coor.x << "  " << coor.y << endl;
                    if (swiat->GetPole(coor)->GetSila() < sila) {
                        cout << "Down" << endl; 
                        pozycja = coor;
                        dir = DOWN;
                    }
                    else
                        coor = pozycja;
                }
            }break;
            case LEFT: {
                if (pozycja.x - step >= 0) {
                    coor.x -= step;
                   // cout << " LEFT    " << coor.x << "  " << coor.y << endl;
                    if (swiat->GetPole(coor)->GetSila() < sila) {
                        cout << "Left" << endl;  
                        pozycja = coor;
                        dir = LEFT;
                    }
                    else
                        coor = pozycja;
                }
            }break;
            case RIGHT: {
                if (pozycja.x + step < swiat->GetSzerokosc()) {
                    coor.x += step;
                    //cout << " RIGHT    " << coor.x << "  " << coor.y << endl;
                    if (swiat->GetPole(coor)->GetSila() < sila) {
                        cout << "Right" << endl;
                        pozycja = coor;
                        dir = RIGHT;
                    }
                    else
                        coor = pozycja;
                }
            }break;
        }
    }

    if (dir != NO_CHANGE)
        cout << "nowa pozycja " << GetZnak() << " " << pozycja.x << " " << pozycja.y << endl;
    else
        cout << "pozycja " << GetZnak() << " nie zmienila sie" << endl;

    return dir;
}
