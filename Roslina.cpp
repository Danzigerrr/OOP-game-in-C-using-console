#include "Roslina.h"
#include "Swiat.h"
Roslina::Roslina(){}
Roslina::~Roslina() {}

void Roslina::Akcja() {
    NormalnaAkcjaRoslin();
}
void Roslina::NormalnaAkcjaRoslin() {
    if (CzyRozprzestrzeniac())
        Split();
}
bool Roslina::CzyRozprzestrzeniac() {
	int szansa = rand() % 100;
	if (szansa <= SZANSA_NA_ROZSIEW) return true;
	else return false;
}

void Roslina::Split() {
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            int Xpos = pozycja.x  - 1 + i;
            int Ypos = pozycja.y - 1 + j;

            COORDINATES coor{ Xpos,Ypos };
            if (Xpos < swiat->GetSzerokosc() && Ypos < swiat->GetWysokosc() && Xpos >= 0 && Ypos >= 0 )//wtedy szuka tylko w zaalokowanej pamieci
               //szukanie pola z Trawa, pole nie moze byc aktulanym polem zajmowanym przez rosline
                if (swiat->GetPole(coor)->GetZnak() == TRAWA && coor.x != pozycja.x && coor.y != pozycja.y) { 
                  
                    char gatunek = GetZnak();
                    switch (gatunek) {
                        case TRAWA: {
                            swiat->SetPole(coor, new Trawa(swiat, coor, 0));
                        }break;
                        case MLECZ: {
                            swiat->SetPole(coor, new Mlecz(swiat, coor, 0));
                        }break;
                        case GUARANA: {
                            swiat->SetPole(coor, new Guarana(swiat, coor, 0));
                        }break;
                        case WILCZEJAGODY: {
                            swiat->SetPole(coor, new WilczeJagody(swiat, coor, 0));
                        }break;
                        case BARSZCZ: {
                            swiat->SetPole(coor, new BarszczSosnowskiego(swiat, coor, 0));
                        }break;
                    }
                    cout << " gatunek " << gatunek << " sie rozsial\n";
                    break; // koniec szukania miejsca do rozsiania
                }
        }
}