#include "Swiat.h"


Swiat::Swiat(const int _width, const int _height)
{
	cout << "utworzono swiat o rozmiarach: szer = " << _width << " wys= " << _height << endl;

	this->szerokosc = _width;
	this->wysokosc = _height;
	this->tura = 0;

	plansza = new Organizm **[_height];
	for (int i = 0; i < _height; i++) plansza[i] = new Organizm *[_width];
	for (int i = 0; i < _height; i++) {
		for (int k = 0; k < _width; k++) plansza[i][k] = new Trawa();
	}

}
void Swiat::RysujSwiat() {
	cout << "\nSWIAT WYGLADA TAK:\n";
	for (int i = 0; i < wysokosc; i++)
		for (int j = 0; j < szerokosc; j++)
			cout << plansza[i][j]->GetZnak() << " ";
}

