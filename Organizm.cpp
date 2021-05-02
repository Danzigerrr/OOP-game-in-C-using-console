#include "Organizm.h"
#include "Swiat.h"

Organizm::Organizm(){}
Organizm::~Organizm(){}

const char Organizm::GetZnak() {
    return znak;
}
int Organizm::GetSila() {
    return this->sila;
}
void Organizm::SetSila(int sila) {
    this->sila = sila;
}
int Organizm::GetInicjatywa() {
    return this->inicjatywa;
}
void Organizm::SetInicjatywa(int inicjatywa) {
    this->inicjatywa = inicjatywa;
}
COORDINATES Organizm::GetPozycja() {
    return this->pozycja;
}
void Organizm::SetPozycja(COORDINATES pos) {
    this->pozycja = pos;
}
int Organizm::GetWiek() {
    return this->wiek;
}
void Organizm::SetWiek(int wiek) {
    this->wiek = wiek;
}
Swiat* Organizm::GetSwiat() {
    return swiat;
}
void Organizm::SetSwiat(Swiat* swiat) {
    this->swiat = swiat;
}
//void Organizm::Akcja() {
//    cout << "\n " << GetZnak() << " wykonuje akcje\n";
//}
void Organizm::NormalnaKolizja(Organizm* atakujacy) {
    if (sila != atakujacy->GetSila()) //sily sa rozne --> wygyrwa silniejszy
    {
        if (sila > atakujacy->GetSila()) //wygrywa obronca
        {
            cout << this->GetZnak() << " DEF wygral\n";

            COORDINATES coor = pozycja;
            Organizm* Org = NULL;
            char gatunek = GetZnak();
            switch (gatunek) {
                case ANTYLOPA: { Org = new Antylopa(swiat, coor, wiek); }break;
                case LIS: { Org = new Lis(swiat, coor, wiek); }break;
                case OWCA: { Org = new Owca(swiat, coor, wiek); }break;
                case WILK: {  Org = new Wilk(swiat, coor, wiek); }break;
                case ZOLW: { Org = new Zolw(swiat, coor, wiek); }break;
                case BARSZCZ: { Org = new BarszczSosnowskiego(swiat, coor, wiek); }break;
                case GUARANA: { Org = new Guarana(swiat, coor, wiek); }break;
                case MLECZ: { Org = new Mlecz(swiat, coor, wiek); }break;
                case TRAWA: { Org = new Trawa(swiat, coor, wiek); }break;
                case WILCZEJAGODY: { Org = new WilczeJagody(swiat, coor, wiek); }break;
                case CZLOWIEK: { Org = new Czlowiek(swiat, coor, wiek); }break;
            }

            swiat->SetPole(pozycja, Org);
        }
        else //wygrywa atakujacy
        {
            if (GetSwiat() == NULL) cout << "NULL pointer";

            cout << "    " << atakujacy->GetZnak() << " ATT wygral z " << GetZnak() << endl;

            COORDINATES coor = atakujacy->GetPozycja();
            Organizm* trawa = new Trawa();
            char znak = swiat->GetPole(coor)->GetZnak();
            cout << "znak -" << znak <<"- " ;

            swiat->GetPlansza()[coor.x][coor.y] = new Trawa();
            cout << "99999999";
       //     swiat->SetPole(pozycja, Org);
        }
    }

    else //jesli sily sa rowne --> wygrywa atakujacy
    {
        cout << atakujacy->GetZnak() << " ATT wygral\n";
        swiat->SetPole(atakujacy->GetPozycja(), new Trawa());
        swiat->SetPole(pozycja, atakujacy);

        cout << "7777777";
    }
}
void Organizm::Kolizja(Organizm* atakujacy) {
    NormalnaKolizja(atakujacy);
}
