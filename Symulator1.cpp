#include "Swiat.h"


int main(){

	cout << "wybierz opcje:" << endl;
	cout << "1. Wczytaj stan gry z pliku *.txt" << endl;
	cout << "2. Rozpocznij nowa gre:" << endl;
	int komenda;
	cin >> komenda;


	switch (komenda)
	{
		case 1: {
			Swiat* swiat = new Swiat();
			swiat->WczytajSwiatZPliku();
		}break;
		case 2: {
			int szer = 0, wys = 0;

			cout << "wpisz szer i wys\n";
			cin >> szer;
			cin >> wys;
			if (szer > 0 && wys > 0) {

				Swiat swiat(szer, wys);

				while (true)
					swiat.WykonajTure();
			}
			else
				cout << "niepoprawne dane!" << endl;
				
		}break;
		default: {
			cout << "niepoprawna komenda" << endl;
			
		}break;
	}
    


    return 0;
}
