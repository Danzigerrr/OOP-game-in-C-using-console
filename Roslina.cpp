#include "Roslina.h"
#include "Swiat.h"
Roslina::Roslina(){}
Roslina::~Roslina() {}

void Roslina::Akcja() {
    NormalnaAkcja();
}
void Roslina::NormalnaAkcja() {
    if (CzyRozprzestrzeniac())
        Split();
}
bool Roslina::CzyRozprzestrzeniac() {
	int szansa = rand() % 100;
	if (szansa <= 20) return true;
	else return false;
}

void Roslina::Split() {
    if (NULL == GetSwiat()) cout << "\nNUUUUUUUUUUUUUUUUUUUUUUUUUULL\n";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            int Xpos = pozycja.x  - 1 + i;
            int Ypos = pozycja.y - 1 + j;
           // cout << " X= " << Xpos << " Y= " << Ypos << endl;
            COORDINATES coor{ Xpos,Ypos };
            if (Xpos < swiat->GetSzerokosc() && Ypos < swiat->GetWysokosc() && Xpos >= 0 && Ypos >= 0 )//wtedy szuka tylko w zaalokowanej pamieci
               
                if (swiat->GetPlansza()[Xpos][Ypos]->GetZnak() == TRAWA && coor.x != GetPozycja().x && coor.y != GetPozycja().y) { //szukanie pola z Trawa
                  
                    char gatunek = GetZnak();
                    switch (gatunek) {
                        case TRAWA: {
                            swiat->GetPlansza()[Xpos][Ypos] = new Trawa(GetSwiat(),coor,0);
                        }break;
                        case MLECZ: {
                            swiat->GetPlansza()[Xpos][Ypos] = new Mlecz(GetSwiat(), coor, 0);
                        }break;
                        case GUARANA: {
                            swiat->GetPlansza()[Xpos][Ypos] = new Guarana(GetSwiat(), coor, 0);
                        }break;
                        case WILCZEJAGODY: {
                            swiat->GetPlansza()[Xpos][Ypos] = new WilczeJagody(GetSwiat(), coor, 0);
                        }break;
                        case BARSZCZ: {
                            swiat->GetPlansza()[Xpos][Ypos] = new BarszczSosnowskiego(GetSwiat(), coor, 0);
                        }break;
                    }

                }
        }
}