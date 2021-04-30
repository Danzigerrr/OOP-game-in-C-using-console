#include "Swiat.h"


Swiat::Swiat(const int _width, const int _height)
{
	cout << "utworzono swiat o rozmiarach: szer = " << _width << " wys= " << _height << endl;

	this->szerokosc = _width;
	this->wysokosc = _height;
	this->tura = 0;

	plansza = new Organizm * *[_height];
	for (int i = 0; i < _height; i++)
		plansza[i] = new Organizm * [_width];


	vector<Organizm*> Y;
	Y.push_back(new Antylopa);
	Y.push_back(new Lis);
	Y.push_back(new Owca);
	Y.push_back(new Wilk);
	Y.push_back(new Zolw);

	Y.push_back(new BarszczSosnowskiego);
	Y.push_back(new Guarana);
	Y.push_back(new Mlecz);
	Y.push_back(new Trawa);
	Y.push_back(new WilczeJagody);

	while (Y.size() < szerokosc * wysokosc)
		Y.push_back(new Trawa);

	random_shuffle(Y.begin(), Y.end());

	for (int i = 0; i < wysokosc; i++) {
		for (int j = 0; j < szerokosc; j++) {
			plansza[i][j] = Y[i * szerokosc + j];
			plansza[i][j]->nadajSwiat(this);
			plansza[i][j]->nadajPozycje(i, j);
		}
	}
}

void Swiat::WczytajSwiatZPliku() {
	char test[] = "test1.txt";
	FILE* fptr;
	fptr = fopen(test, "r");
	if (fptr == NULL) {
		cout << "ERROR opening file";
		exit(1);
	}
	char infoSwiat[50] = {};
	fgets(infoSwiat, 50, fptr);
	int j = 0;
	this->wysokosc = get_value_from_char(infoSwiat, &j);
	this->szerokosc = get_value_from_char(infoSwiat, &j);
	this->tura = get_value_from_char(infoSwiat, &j);

	char infoOrganizmy[50] = {};

	vector<Organizm*> Y;
	while (fgets(infoOrganizmy, 50, fptr) != NULL) {

		if (infoOrganizmy[0] != '/') {
			char gatunek = infoOrganizmy[0];
			
			int i = 2;
			int x = get_value_from_char(infoOrganizmy, &i);
			int y = get_value_from_char(infoOrganizmy, &i);
			int wiek = get_value_from_char(infoOrganizmy, &i);
			int inicjatywa = get_value_from_char(infoOrganizmy, &i);
			int sila = get_value_from_char(infoOrganizmy, &i);
			
			COORDINATES coor;
			coor.x = x;
			coor.y = y;

			Organizm* Org;

			switch (gatunek) {
			case ANTYLOPA: { Org = new Antylopa(this, coor, wiek, inicjatywa, sila);}break;
			case LIS: { Org = new Lis(this, coor, wiek, inicjatywa, sila); }break;
			case OWCA: { Org = new Owca(this, coor, wiek, inicjatywa, sila); }break;
			case WILK: {  Org = new Wilk(this, coor, wiek, inicjatywa, sila);}break;
			case ZOLW: { Org = new Zolw(this, coor, wiek, inicjatywa, sila); }break;
			case BARSZCZ: { Org = new BarszczSosnowskiego(this, coor, wiek, inicjatywa, sila); }break;
			case GUARANA: { Org = new Guarana(this, coor, wiek, inicjatywa, sila); 	}break;
			case MLECZ: { Org = new Mlecz(this, coor, wiek, inicjatywa, sila); 	}break;
			case TRAWA: { Org = new Trawa(this, coor, wiek, inicjatywa, sila); 	}break;
			case WILCZEJAGODY: { Org = new WilczeJagody(this, coor, wiek, inicjatywa, sila); }break;
			}

			plansza[x][y] = Org;
			plansza[x][y]->nadajSwiat(this);
			plansza[x][y]->nadajPozycje(x,y);
			
		}
	}
	fclose(fptr);

	cout << "POMYŚLNIE WCZYTANO ŚWIAT:\n";
	this->RysujSwiat();
}

int get_value_from_char(char znak[50], int* iterator)
{
	int result = 0, i = 0;
	while (znak[*iterator + i] >= 48 && znak[*iterator + i] <= 57)
	{
		result = result * 10 + (znak[*iterator + i] - 48);
		i++;
	}
	*iterator += 1 + i;
	return result;
}
Swiat::~Swiat() {
	cout << "Destruktor Swiata\n";
	for (int i = 0; i < wysokosc; i++) {
		for (int k = 0; k < szerokosc; k++)
			delete plansza[i][k];
	}
	for (int i = 0; i < wysokosc; i++) {
		delete[] plansza[i];
	}
	delete[] plansza;
}

void Swiat::RysujSwiat() {
	cout << "\nSWIAT WYGLADA TAK:\n";
	for (int i = 0; i < wysokosc; i++)
		for (int j = 0; j < szerokosc; j++)
			cout << plansza[i][j]->GetZnak() << " ";
}

vector<Organizm*> Swiat::wezWszystkieOrganizmy() {
	vector<Organizm*> res;
	for (int i = 0; i < wysokosc; i++) {
		for (int j = 0; j < szerokosc; j++) {
			res.push_back(plansza[i][j]);
		}
	}
	return res;
}

void Swiat::WykonajTure() {
	vector<Organizm*> w = wezWszystkieOrganizmy();
	sort(w.begin(), w.end(), cmp);
	for (auto o_ptr : w) {
		o_ptr->Akcja();
	}
	tura++;
}