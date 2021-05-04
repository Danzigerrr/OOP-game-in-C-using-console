#include "Organizm.h"
#include "Swiat.h"
#define ILOSC_ORGANIZMU_NA_POCZATKU 20 //%

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
	COORDINATES coor1{ 0,0 };
	Y.push_back(new Czlowiek(this,coor1,0)); // tylko jeden czlowiek
	
	int iloscPol = szerokosc * wysokosc;
	int iloscOrg = iloscPol * ILOSC_ORGANIZMU_NA_POCZATKU / 100;
	cout << "Swiat bedzie mial " << iloscOrg << " organizmow, co stanowi " << ILOSC_ORGANIZMU_NA_POCZATKU << "% ilsoci pol.\n";
	int iterator = 1;
	while(iloscOrg > iterator){
		int i = iterator % ILOSC_GATUNKOW_BEZ_CZLOWIEKA;
		Organizm* Org = NULL;
		switch (i) {
			case 1: { Org = new Antylopa; }break;
			case 2: { Org = new Lis; }break;
			case 3: { Org = new Owca; }break;
			case 4: {  Org = new Wilk; }break;
			case 5: { Org = new Zolw; }break;
			case 6: { Org = new BarszczSosnowskiego; }break;
			case 7: { Org = new Guarana; }break;
			case 8: { Org = new Mlecz; }break;
			case 9: { Org = new Trawa; }break;
			case 0: { Org = new WilczeJagody; }break;
		}
		Y.push_back(Org);
		iterator++;
	}

	
	COORDINATES coor{ 0,0 };
	while (Y.size() < szerokosc * wysokosc)
		Y.push_back(new Trawa());

	std::random_shuffle(Y.begin(), Y.end());

	//Y.reserve(Y.size());

	for (int j = 0; j < szerokosc; j++) {
		for (int i = 0; i < wysokosc; i++) {
			int id = j * wysokosc + i;
			COORDINATES coor{ j,i }; 

			Organizm* Org = NULL;
			char gatunek = Y[id]->GetZnak();
			int wiek = 0;
			switch (gatunek) {
				case ANTYLOPA: { Org = new Antylopa(this, coor, wiek); }break;
				case LIS: { Org = new Lis(this, coor, wiek); }break;
				case OWCA: { Org = new Owca(this, coor, wiek); }break;
				case WILK: {  Org = new Wilk(this, coor, wiek); }break;
				case ZOLW: { Org = new Zolw(this, coor, wiek); }break;
				case BARSZCZ: { Org = new BarszczSosnowskiego(this, coor, wiek); }break;
				case GUARANA: { Org = new Guarana(this, coor, wiek); }break;
				case MLECZ: { Org = new Mlecz(this, coor, wiek); }break;
				case TRAWA: { Org = new Trawa(this, coor, wiek); }break;
				case WILCZEJAGODY: { Org = new WilczeJagody(this, coor, wiek); }break;
				case CZLOWIEK: { Org = new Czlowiek(this, coor, wiek); }break;
			}
			SetPole(coor, Org);
		}
	}

	RysujSwiat();
}
Swiat::Swiat() {
	cout << "witaj nowy swiecie!\n";
	szerokosc = 0;
	wysokosc = 0;
	tura = 0;
	plansza = NULL;
}
void Swiat::GetHumanCommand() {

	if (GetHuman() != NULL) {
		Czlowiek* Human = (Czlowiek*)GetHuman();
		cout << "Oblsuga:\n";
		cout << "Strzalki -> ruch czlowieka\n";
		cout << "Przycisk TAB -> zapis pliku\n";
		cout << "Przycisk ESC -> koniec programu\n";
		cout << endl;
		int UmiejetnoscAktywnaPrzez = Human->GetUmiejetnoscAktywnaPrzez();
		int UmiejetnoscOdnawianaPrzez = Human->GetUmiejetnoscOdnawianaPrzez();
		COORDINATES pozycja = Human->GetPozycja();
		int PrzyciskSpecjalny = _getch(); // podwojny input

		switch (PrzyciskSpecjalny) {
			case ESC: {
				exit(1);
			}break;
			case TAB: {
				ZapiszSwiatDoPliku();
				exit(1);
			}break;
			case ENTER: {
				if (UmiejetnoscAktywnaPrzez == 0 && UmiejetnoscOdnawianaPrzez == 0) {
					std::cout << "Specjalna umiejetnosc aktywowana";
					Human->SetUmiejetnoscAktywnaPrzez(UMIEJETNOSC_AKTYWNA);
				}
				else {
					if(UmiejetnoscAktywnaPrzez > 0 ) cout << "Specjalna umiejetnosc jest w uzyciu";
					if(UmiejetnoscOdnawianaPrzez > 0) cout << "Specjalna umiejetnosc jest odnawiana";
				}
			}break;

			default: {
				Human->SetKierunekRuchuCzlowieka(_getch());
				break;
			}	
		}
	}
	else {
		cout << "czlowiek nie istnieje! GAME OVER";
		exit(1);
	}
		
}

void Swiat::ZapiszSwiatDoPliku() {
	char* nazwaPliku = WczytajNazwePliku();
	ofstream myfile(nazwaPliku);
	if (myfile.is_open())
	{
		myfile << szerokosc << " " << wysokosc << " "<< tura << "\n";
		vector<Organizm*> w = wezWszystkieOrganizmy();
		for (auto org : w) {
			if (org->GetZnak() != TRAWA) {
				cout << "zapisuje " << org->GetZnak() << endl;
				myfile << org->GetZnak() << " " << org->GetPozycja().x << " " << org->GetPozycja().y << " " << org->GetWiek() << "\n";
			}
		}

		
		cout << "Pomyslnie zapisano gre w pliku " << nazwaPliku << endl;
		myfile.close();
	}
	else {
		cout << "Unable to open this file.";
		exit(1);
	}
}

void Swiat::WczytajOrganizmyZPliku(FILE* fptr) {


	char infoOrganizmy[50] = {};
	while (fgets(infoOrganizmy, 50, fptr) != NULL) {

		if (infoOrganizmy[0] != '/') //komentarz
		{
			char gatunek = infoOrganizmy[0];

			int i = 2;
			int x = get_value_from_char(infoOrganizmy, &i);
			int y = get_value_from_char(infoOrganizmy, &i);
			int wiek = get_value_from_char(infoOrganizmy, &i);

			if (x >= szerokosc || y >= wysokosc) {
				cout << "niepoprawna pozycja ";
				if (x >= szerokosc) cout << "x ";
				if (y >= wysokosc)  cout << "y ";
				cout << "ktoregos orgaznimu!";
				exit(1);
			}

			COORDINATES coor{ x,y };

			Organizm* Org = NULL;

			switch (gatunek) {
			case ANTYLOPA: { Org = new Antylopa(this, coor, wiek); }break;
			case LIS: { Org = new Lis(this, coor, wiek); }break;
			case OWCA: { Org = new Owca(this, coor, wiek); }break;
			case WILK: {  Org = new Wilk(this, coor, wiek); }break;
			case ZOLW: { Org = new Zolw(this, coor, wiek); }break;
			case BARSZCZ: { Org = new BarszczSosnowskiego(this, coor, wiek); }break;
			case GUARANA: { Org = new Guarana(this, coor, wiek); }break;
			case MLECZ: { Org = new Mlecz(this, coor, wiek); }break;
			case TRAWA: { Org = new Trawa(this, coor, wiek); }break;
			case WILCZEJAGODY: { Org = new WilczeJagody(this, coor, wiek); }break;
			case CZLOWIEK: { Org = new Czlowiek(this, coor, wiek); }break;
			}

			if (Org == NULL) {
				cout << "niepoprawna nazwa organizmu!";
				exit(1);
			}
			else {

				if (plansza[x][y]->GetZnak() != TRAWA)
					cout << "Pole " << x << " " << y << " jest juz zajete przez " << plansza[x][y]->GetZnak() << endl;
				else {

					if (GetHuman() != NULL && Org->GetZnak() == CZLOWIEK)
						cout << "Na swiecie moze istniec tylko jeden czlowiek!\n";
					else {
						cout << "Nowy organizm: " << gatunek << "  pozycja: " << x << " " << y << "  wiek: " << wiek << endl;
						SetPole(coor, Org);

					}
				}
			}
		}
	}
}
void Swiat::WczytajInfoOSwiecieZPliku(FILE* fptr) {
	char infoSwiat[50] = {};
	fgets(infoSwiat, 50, fptr);
	int j = 0;
	this->wysokosc = get_value_from_char(infoSwiat, &j);
	this->szerokosc = get_value_from_char(infoSwiat, &j);
	this->tura = get_value_from_char(infoSwiat, &j);
}
void Swiat::UtworzPlanszeZPliku() {
	system("CLS");
	cout << "Swiat: szer= " << szerokosc << " " << " wys= " << wysokosc << " tura= " << tura << endl;

	plansza = new Organizm * *[szerokosc];
	for (int i = 0; i < szerokosc; i++) {
		plansza[i] = new Organizm * [wysokosc];
	}

	//cala plansza to trawa, potem sie wstawia zwierzeta
	for (int j = 0; j < szerokosc; j++) {
		for (int i = 0; i < wysokosc; i++) {
			COORDINATES coor{ j,i };
			SetPole(coor, new Trawa(this, coor, 0));
		}
	}
}
char* Swiat::WczytajNazwePliku() {
	system("CLS");
	cout << "wpisz nazwe pliku:\n";
	string nazwaPliku;
	cin >> nazwaPliku;
	nazwaPliku += ".txt";
	//przekonwertowanie na tablice charow
	int n = nazwaPliku.length();
	char* nazwaPlikuTabChar = new char[n + 1];
	strcpy(nazwaPlikuTabChar, nazwaPliku.c_str());
	return nazwaPlikuTabChar;
}
void Swiat::WczytajSwiatZPliku() {

	char* nazwaPliku = WczytajNazwePliku();
	
	FILE* fptr = fopen(nazwaPliku, "r");
	if (fptr == NULL) {
		std::cout << "ERROR opening file";
		exit(1);
	}

	WczytajInfoOSwiecieZPliku(fptr);
	if (wysokosc > 0 && szerokosc > 0 && tura > 0) {
		UtworzPlanszeZPliku();
		WczytajOrganizmyZPliku(fptr);

		cout << "POMYSLNIE WCZYTANO SWIAT:\n";
		RysujSwiat();
	}
	fclose(fptr);

	while (true) 
		WykonajTure();
	
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

void Swiat::WykonajTure() {

	GetHumanCommand();

	tura++;
	std::cout << "Wykonywanie " << tura << " tury:\n";

	vector<Organizm*> w = wezWszystkieOrganizmy();
	//sort(w.begin(), w.end(), cmp);
	int iloscwszystkichorg = 0;
	for (auto o_ptr : w) {
		iloscwszystkichorg++;
		o_ptr->SetWykonalRuch(false);
	}

	int kolejnyorganizm = 0;

	for (int j = 0; j < iloscwszystkichorg; j++) {
		Organizm *org = w.front();
		if (org->GetWykonalRuch() == false) {
			COORDINATES coor = org->GetPozycja();
			if(org -> GetZnak() != TRAWA) // dal trawy nie wypisujemy tego
			cout << org->GetZnak() <<  " na poz " << coor.x << " " << coor.y << " wykonuje akcje \n";
			
			if(org->GetZnak() == LIS)
				org->Akcja();
			else

				org->Akcja();

			//RysujSwiat();

			int aktualnyWiek = org->GetWiek();
			org->SetWiek(aktualnyWiek + 1);
			org->SetWykonalRuch(true);
			//Sleep(100);
		}
		w = wezWszystkieOrganizmy(); // aktualizacja vektora
	//	std::sort(w.begin(), w.end(), cmp);
		kolejnyorganizm++;
		for (int i = 0; i < kolejnyorganizm; i++) {
			w.erase(w.begin()); // pop front
		}

	}
	RysujSwiat();
	PrzygotujKolejnaRunde();

}

void Swiat::PrzygotujKolejnaRunde() {
	
	while (std::cin.get() != 'n' ) {
		cout << "koniec tury, klinknij klawisz n + enter\n";
	}

	std::system("CLS");
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

int Swiat::GetWysokosc() {
	return wysokosc;
}

int Swiat::GetSzerokosc() {
	return szerokosc;
}

int Swiat::GetTura() {
	return tura;
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

bool cmp(Organizm* o1, Organizm* o2) {
	if (o1->GetInicjatywa() != o2->GetInicjatywa()) {
		return o1->GetInicjatywa() < o2->GetInicjatywa();
	}
	return o1->GetWiek() < o2->GetWiek();
}

int Swiat::get_value_from_char(char* znak, int* iterator)
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

vector<Organizm*> Swiat::wezWszystkieOrganizmy() {
	vector<Organizm*> res;
	for (int i = 0; i < szerokosc; i++) {
		for (int j = 0; j < wysokosc; j++) {
			COORDINATES coor{ i,j };
			res.push_back(GetPole(coor));
		}
	}
	return res;
}

Organizm* Swiat::GetHuman() {

	vector<Organizm*> w = wezWszystkieOrganizmy();

	for (auto o_ptr : w) {
		if (o_ptr->GetZnak() == 'H')
			return o_ptr;
	}
	return NULL;

}




