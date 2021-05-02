#include "Swiat.h"

//int KierunekRuchuCzlowieka;

int main(){

    int szer=10, wys=4;

    /*cout << "wpisz szer i wys\n";
    cin >> szer;
    cin >> wys;*/

    Swiat swiat(szer, wys);
    swiat.testuj();
    while (true) {
        swiat.WykonajTure(); 
        swiat.testuj();
    }


    return 0;
}
