#include "Swiat.h"
#define ILOSC_ORGANIZMU_NA_POCZATKU 1

Swiat::Swiat(const int _width, const int _height)
{
	std::cout << "utworzono swiat o rozmiarach: szer = " << _width << " wys= " << _height << endl;

	this->szerokosc = _width;
	this->wysokosc = _height;
	this->tura = 0;

	plansza = new Organizm **[szerokosc];
	for (int i = 0; i < szerokosc; i++) {
		plansza[i] = new Organizm * [wysokosc];
	}


	vector<Organizm*> Y;
	Y.push_back(new Czlowiek); // tylko jeden czlowiek
	
	for (int i = 0; i < ILOSC_ORGANIZMU_NA_POCZATKU; i++) {
		Y.push_back(new Antylopa);
		//Y.push_back(new Lis);
		//Y.push_back(new Owca);
		//Y.push_back(new Wilk);
		//Y.push_back(new Zolw);

		//Y.push_back(new BarszczSosnowskiego);
		//Y.push_back(new Guarana);
		//Y.push_back(new Mlecz());
		//Y.push_back(new WilczeJagody);
	}
	
	COORDINATES coor{ 0,0 };
	while (Y.size() < szerokosc * wysokosc)
		Y.push_back(new Trawa());

	random_shuffle(Y.begin(), Y.end());


	for (int j = 0; j < szerokosc; j++) {
		for (int i = 0; i < wysokosc; i++) {
			int id = j * wysokosc + i;
			plansza[j][i] = Y[id];
			plansza[j][i]->SetSwiat(this);

			COORDINATES coor{ j,i };

			plansza[j][i]->SetPozycja(coor);
		}
	}

	RysujSwiat();
}

Organizm* Swiat::GetHuman() {

	vector<Organizm*> w = wezWszystkieOrganizmy();

	for (auto o_ptr : w) {
		if (o_ptr->GetZnak() == 'H')
			return o_ptr;
	}
	return NULL;

}
void Swiat::GetHumanCommand() {
	Czlowiek* Human = (Czlowiek*)GetHuman();
	int UmiejetnoscAktywnaPrzez = Human->GetUmiejetnoscAktywnaPrzez();
	int UmiejetnoscOdnawianaPrzez = Human->GetUmiejetnoscOdnawianaPrzez();
	COORDINATES pozycja = Human->GetPozycja();
	int PierwszyChar = _getch(); // podwojny input

	if (PierwszyChar == ESC) exit(1);
	if (PierwszyChar == ENTER && UmiejetnoscAktywnaPrzez == 0 && UmiejetnoscOdnawianaPrzez == 0) {
		std::cout << "Specjalna umiejetnosc aktywowana";
		Human->SetUmiejetnoscAktywnaPrzez(UMIEJETNOSC_AKTYWNA);
	}
	else {
		Human->SetKierunekRuchuCzlowieka(_getch());
	}
}

void Swiat::WczytajSwiatZPliku() {
	char test[] = "test1.txt";
	FILE* fptr;
	fptr = fopen(test, "r");
	if (fptr == NULL) {
		std::cout << "ERROR opening file";
		exit(1);
	}

	char infoSwiat[50] = {};
	fgets(infoSwiat, 50, fptr);
	int j = 0;
	this->wysokosc = get_value_from_char(infoSwiat, &j);
	this->szerokosc = get_value_from_char(infoSwiat, &j);
	this->tura = get_value_from_char(infoSwiat, &j);


	char infoOrganizmy[50] = {};
	while (fgets(infoOrganizmy, 50, fptr) != NULL) {

		if (infoOrganizmy[0] != '/') //komentarz
		{
			char gatunek = infoOrganizmy[0];
			
			int i = 2;
			int x = get_value_from_char(infoOrganizmy, &i);
			int y = get_value_from_char(infoOrganizmy, &i);
			int wiek = get_value_from_char(infoOrganizmy, &i);
			
			COORDINATES coor{x,y};

			Organizm* Org = NULL;

			switch (gatunek) {
				case ANTYLOPA: { Org = new Antylopa(this, coor, wiek);}break;
				case LIS: { Org = new Lis(this, coor, wiek); }break;
				case OWCA: { Org = new Owca(this, coor, wiek); }break;
				case WILK: {  Org = new Wilk(this, coor, wiek);}break;
				case ZOLW: { Org = new Zolw(this, coor, wiek); }break;
				case BARSZCZ: { Org = new BarszczSosnowskiego(this, coor, wiek); }break;
				case GUARANA: { Org = new Guarana(this, coor, wiek); }break;
				case MLECZ: { Org = new Mlecz(this, coor, wiek); }break;
				case TRAWA: { Org = new Trawa(this, coor, wiek); }break;
				case WILCZEJAGODY: { Org = new WilczeJagody(this, coor, wiek); }break;
				case CZLOWIEK: { Org = new Czlowiek(this, coor, wiek); }break;
			}

			plansza[x][y] = Org;
			plansza[x][y]->SetSwiat(this);
			plansza[x][y]->SetPozycja(coor);
		}
	}
	fclose(fptr);

	std::cout << "POMYŚLNIE WCZYTANO ŚWIAT:\n";
	this->RysujSwiat();
}

int Swiat::get_value_from_char(char *znak, int* iterator)
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
	std::cout << "Destruktor Swiata\n";
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
	std::cout << "\nOTO SWIAT:\n  ";
	for (int i = 0; i < szerokosc; i++) cout << i << " ";
	cout << endl;

	for (int i = 0; i < wysokosc; i++) {
		cout <<  i << " ";
		for (int j = 0; j < szerokosc; j++)
			std::cout << plansza[j][i]->GetZnak() << " ";
		cout << endl;
	}
	cout << " koniec rsyowania swiata\n ";

	if (GetHuman() != NULL)
		cout << "Pozycja czlowieka: " << GetHuman()->GetPozycja().x << " " << GetHuman()->GetPozycja().y << endl;
	else
		cout << "Czlowiek nie istnieje\n";
}

vector<Organizm*> Swiat::wezWszystkieOrganizmy() {
	vector<Organizm*> res;
	for (int i = 0; i < szerokosc; i++) {
		for (int j = 0; j < wysokosc; j++) {
			res.push_back(plansza[i][j]);
		}
	}
	return res;
}

void Swiat::WykonajTure() {
	
	GetHumanCommand();

	tura++;
	std::cout << "Wykonywanie " << tura << " tury:\n";

	vector<Organizm*> w = wezWszystkieOrganizmy();
	//std::sort(w.begin(), w.end(), cmp);
	int iloscwszystkichorg = 0;
	for (auto o_ptr : w) {
		iloscwszystkichorg++;
		o_ptr->SetWykonalRuch(false);
	}

	int kolejnyorganizm = 0;

	for (int j = 0; j < iloscwszystkichorg; j++) {
		Organizm *o_ptr = w.front();
		if (o_ptr->GetWykonalRuch() == false) {
			cout << "\n\n---------\n\n  " << o_ptr->GetZnak() << " wykonuje akcje \n";

			COORDINATES coor = o_ptr->GetPozycja();
			cout << " jest na pozycji " << coor.x << " " << coor.y;
		

			o_ptr->Akcja();

			RysujSwiat();

			int aktualnyWiek = o_ptr->GetWiek();
			o_ptr->SetWiek(aktualnyWiek + 1);
			o_ptr->SetWykonalRuch(true);
		}
		w = wezWszystkieOrganizmy(); // aktualizacja vektora
		//std::sort(w.begin(), w.end(), cmp);
		kolejnyorganizm++;
		for (int i = 0; i < kolejnyorganizm; i++) {
			w.erase(w.begin()); // pop front
		}

	}
	PrzygotujKolejnaRunde();

}

void Swiat::testuj() {
	vector<Organizm*> w = wezWszystkieOrganizmy();
	for (auto o_ptr : w) {
		if (NULL == o_ptr->GetSwiat()) cout << "\n dla" << o_ptr->GetZnak() << " swiat is NUUUUUUUUUUUUUUUUUUUUUUUUUULL\n";
	}
}

void Swiat::PrzygotujKolejnaRunde() {
	system("CLS");
	RysujSwiat();
	Czlowiek* Human = (Czlowiek*)GetHuman();
	if (Human == NULL) {
		cout << "GAME OVER";
		exit(1);
	}
	else {
		cout << "Niech czlowiek wykona ruch: " << endl;
		if (Human->GetUmiejetnoscAktywnaPrzez() > 0) cout << "aktywnosc aktywna przez:" << Human->GetUmiejetnoscAktywnaPrzez() << endl;
		if (Human->GetUmiejetnoscOdnawianaPrzez() > 0) cout << "aktywnosc odnawiana przez:" << Human->GetUmiejetnoscOdnawianaPrzez() << endl;
	}
}

void Swiat::SetPole(COORDINATES coor, Organizm* org) {
	this->plansza[coor.x][coor.y] = org;
}

Organizm* Swiat::GetPole(COORDINATES coor) {
	if (this == NULL) cout << "NULL";
	return plansza[coor.x][coor.y];
}

Organizm*** Swiat::GetPlansza() {
	return plansza;
}

int Swiat::GetWysokosc() {
	return wysokosc;
}
int Swiat::GetSzerokosc() {
	return szerokosc;
}
int Swiat::GetTura() {
	return tura;
}

void Swiat::SetPlansza(Organizm*** plansza) {
	this->plansza = plansza;
}



bool Swiat::cmp(Organizm *o1, Organizm *o2) {
	if (o1->GetInicjatywa() != o2->GetInicjatywa()) {
		return o1->GetInicjatywa() < o2->GetInicjatywa();
	}
	return o1->GetWiek() < o2->GetWiek();
}




