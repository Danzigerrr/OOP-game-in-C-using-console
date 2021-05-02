#include "Swiat.h"

//int KierunekRuchuCzlowieka;

int main(){

    int szer=3, wys=3;

    /*cout << "wpisz szer i wys\n";
    cin >> szer;
    cin >> wys;*/

    Swiat swiat(szer, wys);

    while (true) {
        swiat.WykonajTure();
    }


    return 0;
}
