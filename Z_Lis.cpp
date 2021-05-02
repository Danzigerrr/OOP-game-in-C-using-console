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
            else return NO_CHANGE;

            case UP: {
                if (pozycja.y - step >= 0) 
                    // lis nigdy nie ruszy sie na ple zajmowae prez organizm silniejszy niz on
                    if (this->swiat->GetPlansza()[pozycja.x][pozycja.y - step]->GetSila() < sila) { 
                    cout << "Up" << endl;//key up
                    pozycja.y -= step;
                    dir = UP;
                }
            }break;
            case DOWN: {
                if (pozycja.y + step <= swiat->GetWysokosc()) 
                    // lis nigdy nie ruszy sie na ple zajmowae prez organizm silniejszy niz on
                    if (swiat->GetPlansza()[pozycja.x][pozycja.y + step]->GetSila() < sila) {
                    cout << "Down" << endl;  // key down
                    pozycja.y += step;
                    dir = DOWN;
                }
            }break;
            case LEFT: {
                if (pozycja.x - step >= 0) 
                    // lis nigdy nie ruszy sie na ple zajmowae prez organizm silniejszy niz on
                    if (swiat->GetPlansza()[pozycja.x - step][pozycja.y]->GetSila() < sila) {
                    cout << "Left" << endl;  // key left
                    pozycja.x -= step;
                    dir = LEFT;
                }
            }break;
            case RIGHT: {
                if (pozycja.x + step <= swiat->GetSzerokosc()) 
                    // lis nigdy nie ruszy sie na ple zajmowae prez organizm silniejszy niz on
                    if (swiat->GetPlansza()[pozycja.x + step][pozycja.y]->GetSila() < sila) {
                    cout << "Right" << endl;  // key right
                    pozycja.x += step;
                    dir = RIGHT;
                }
            }break;
        }
    }
    return dir;
}
