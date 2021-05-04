#include "Organizm.h"
#include "Swiat.h"


Swiat::Swiat(const int _width, const int _height)
{
	std::cout << "utworzono swiat o rozmiarach: szer = " << _width << " wys= " << _height << endl;

	this->szerokosc = _width;
	this->wysokosc = _height;
	this->tura = 0;

	plansza = new Organizm **[szerokosc];
	for (int i = 0; i < szerokosc; i++) 
		plansza[i] = new Organizm * [wysokosc];
	

	vector<Organizm*> Y;
	COORDINATES coor1{ 0,0 };
	Y.push_back(new Czlowiek(this,coor1,0)); // tylko jeden czlowiek
	
	int iloscWszystkichPol = szerokosc * wysokosc;
	int iloscOrg = iloscWszystkichPol * ILOSC_ORGANIZMU_NA_POCZATKU / 100;
	std::cout << "Swiat bedzie mial " << iloscOrg << " organizmow, co stanowi " << ILOSC_ORGANIZMU_NA_POCZATKU << "% ilosci pol.\n";
	int iterator = 1;
	while(iloscOrg > iterator){
		int i = iterator % ILOSC_GATUNKOW_BEZ_CZLOWIEKA;
		Organizm* Org = NULL;
		switch (i) {
			case 0: { Org = new Wilk; }break;
			case 1: { Org = new Antylopa; }break;
			case 2: { Org = new Lis; }break;
			case 3: { Org = new Owca; }break;
			case 4: { Org = new Zolw; }break;
			case 5: { Org = new WilczeJagody; }break;
			case 6: { Org = new BarszczSosnowskiego; }break;
			case 7: { Org = new Guarana; }break;
			case 8: { Org = new Mlecz; }break;
			case 9: { Org = new Trawa; }break;
		}
		Y.push_back(Org);
		iterator++;
	}
	
	COORDINATES coor{ 0,0 };
	while (Y.size() < iloscWszystkichPol)
		Y.push_back(new Trawa());

	std::random_shuffle(Y.begin(), Y.end());

	for (int x = 0; x < szerokosc; x++) {
		for (int y = 0; y < wysokosc; y++) {
			int id = x * wysokosc + y;
			COORDINATES coor{ x,y }; 

			char gatunek = Y[id]->GetZnak();
			int wiek = 0;
			Organizm* Org = StworzOrganizmTegoGatunku(gatunek, coor, wiek);
			SetPole(coor, Org);
		}
	}

	RysujSwiat();
}
Swiat::Swiat() {
	std::cout << "witaj nowy swiecie!\n";
	szerokosc = 0;
	wysokosc = 0;
	tura = 0;
	plansza = NULL;
}
void Swiat::GetHumanCommand() {

	if (GetHuman() != NULL) {
		Czlowiek* Human = (Czlowiek*)GetHuman();
		std::cout << "Oblsuga:\n";
		std::cout << "Strzalki -> ruch czlowieka\n";
		std::cout << "Przycisk TAB -> zapis pliku\n";
		std::cout << "Przycisk ESC -> koniec programu\n";
		std::cout << endl;
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
					if(UmiejetnoscAktywnaPrzez > 0 ) std::cout << "Specjalna umiejetnosc jest w uzyciu";
					if(UmiejetnoscOdnawianaPrzez > 0) std::cout << "Specjalna umiejetnosc jest odnawiana";
				}
			}break;
			default: {
				Human->SetKierunekRuchuCzlowieka(_getch());
				break;
			}	
		}
	}
	else {
		std::cout << "czlowiek nie istnieje! GAME OVER";
		exit(1);
	}
		
}

void Swiat::ZapiszSwiatDoPliku() {
	char* nazwaPliku = WczytajNazwePliku();
	ofstream myfile(nazwaPliku);
	if (myfile.is_open())
	{
		myfile << szerokosc << " " << wysokosc << " "<< tura << iloscOrgNaPoczatku << "\n";
		vector<Organizm*> w = wezWszystkieOrganizmy();
		for (auto org : w) {
			if (org->GetZnak() != TRAWA) {
				myfile << org->GetZnak() << " " << org->GetPozycja().x << " " << org->GetPozycja().y << " " << org->GetWiek() << "\n";

				std::cout << "zapisano " << org->GetZnak() << " " << org->GetPozycja().x << " " << org->GetPozycja().y << " " << org->GetWiek() << "\n";
			}
		}

		system("CLS");
		std::cout << "Pomyslnie zapisano gre w pliku " << nazwaPliku << endl;
		myfile.close();
	}
	else {
		std::cout << "I'm sorry, I am Unable to open file with name " << nazwaPliku << endl;;
		exit(1);
	}
}


Organizm* Swiat::StworzOrganizmTegoGatunku(char gatunek, COORDINATES coor, int wiek) {
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
	return Org;
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
				std::cout << "niepoprawna pozycja ";
				if (x >= szerokosc) std::cout << "x ";
				if (y >= wysokosc)  std::cout << "y ";
				std::cout << "ktoregos orgaznimu!";
				exit(1);
			}

			COORDINATES coor{ x,y };

			Organizm* Org = StworzOrganizmTegoGatunku(gatunek, coor, wiek);

			if (Org == NULL) {
				std::cout << "niepoprawna nazwa organizmu!";
				exit(1);
			}
			else {

				if (plansza[x][y]->GetZnak() != TRAWA)
					std::cout << "Pole " << x << " " << y << " jest juz zajete przez " << plansza[x][y]->GetZnak() << endl;
				else {

					if (GetHuman() != NULL && Org->GetZnak() == CZLOWIEK)
						std::cout << "Na swiecie moze istniec tylko jeden czlowiek!\n";
					else {
						std::cout << "Nowy organizm: " << gatunek << "  pozycja: " << x << " " << y << "  wiek: " << wiek << endl;
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
	this->iloscOrgNaPoczatku = get_value_from_char(infoSwiat, &j);
}
void Swiat::UtworzPlanszeZPliku() {
	system("CLS");
	std::cout << "Swiat: szer= " << szerokosc << " " << " wys= " << wysokosc << " tura= " << tura << endl;

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
	std::cout << "wpisz nazwe pliku:\n";
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

		std::cout << "POMYSLNIE WCZYTANO SWIAT:\n";
		RysujSwiat();
	}
	fclose(fptr);

	while (true) 
		WykonajTure();
	
}
string Swiat::ZapiszPoczatkowySwiat() {
	std::stringstream res;
	res << "\nOTO SWIAT:\n  ";
	for (int i = 0; i < szerokosc; i++) res << i << " ";
	res << endl;

	for (int i = 0; i < wysokosc; i++) {
		res << i << " ";
		for (int j = 0; j < szerokosc; j++)
			res << plansza[j][i]->GetZnak() << " ";
		res << endl;
	}

	if (GetHuman() != NULL) {
		Czlowiek *H = (Czlowiek*)GetHuman();
		res << "Czlowiek: " << H->GetPozycja().x << " " << H->GetPozycja().y <<" sila: " << H->GetSila() <<  endl;
		if (H->GetUmiejetnoscAktywnaPrzez() > 0) { std::cout << "Specjalna umiejetnosc aktywna przez: " << H->GetUmiejetnoscAktywnaPrzez() << endl; }
		if (H->GetUmiejetnoscOdnawianaPrzez() > 0) { std::cout << "Specjalna umiejetnosc odnawiana przez: " << H->GetUmiejetnoscOdnawianaPrzez() << endl; }

	}
	else
		res << "Czlowiek nie istnieje\n";

	string result = res.str();
	return result;
}

void Swiat::RysujSwiat() {
	std::cout << "\nOTO SWIAT:\n  ";
	for (int i = 0; i < szerokosc; i++) std::cout << i << " ";
	std::cout << endl;

	for (int i = 0; i < wysokosc; i++) {
		std::cout <<  i << " ";
		for (int j = 0; j < szerokosc; j++)
			std::cout << plansza[j][i]->GetZnak() << " ";
		std::cout << endl;
	}

	if (GetHuman() != NULL)
		std::cout << "Pozycja czlowieka: " << GetHuman()->GetPozycja().x << " " << GetHuman()->GetPozycja().y << endl;
	else
		std::cout << "Czlowiek nie istnieje\n";
}

bool Swiat::SprawdzCzySaAktywneOrganizmy() {
	for (int i = 0; i < wysokosc; i++) 
		for (int j = 0; j < szerokosc; j++)
			if (plansza[j][i]->GetWykonalRuch() == false)
				return true;

	return false;
}

void Swiat::WykonajTure() {

	GetHumanCommand();

	string StarySwiat = ZapiszPoczatkowySwiat();

	tura++;
	std::cout << "Wykonywanie " << tura << " tury:\n";

	vector<Organizm*> w = wezWszystkieOrganizmy();
	sort(w.begin(), w.end(), cmp);
	for (auto o_ptr : w) {
		o_ptr->SetWykonalRuch(false);
	}

	Organizm* org = w.front();

	while(true){
		if (org->GetWykonalRuch() == false) {

			COORDINATES coor = org->GetPozycja();
			if(org -> GetZnak() != TRAWA) // dal trawy nie pokazuj
			std::cout << org->GetZnak() << " z inicj= " << org->GetInicjatywa() << " z wiekiem= " << org->GetWiek() << " na poz= " << coor.x << " " << coor.y <<  " wykonuje akcje: \n";

			org->Akcja();

			org->SetWiek(org->GetWiek() + 1);
			org->SetWykonalRuch(true);
		}
		if (SprawdzCzySaAktywneOrganizmy()) {

			w = wezWszystkieOrganizmy(true); // aktualizacja vektora

			std::sort(w.begin(), w.end(), cmp);
			org = w.front();
		}
		else
			break;
	}

	std::cout << "\n\n\n\tSTARY SWIAT:" << endl << StarySwiat << endl;;

	std::cout << "\n\tNOWY SWIAT:" << endl;
	RysujSwiat();
	PrzygotujKolejnaRunde();

}

void Swiat::PrzygotujKolejnaRunde() {
	
	vector<Organizm*> w = wezWszystkieOrganizmy();
	for (auto org : w) {
		org->SetWykonalRuch(false);
	}


	while (std::cin.get() != 'n' ) {
		std::cout << "koniec tury, klinknij klawisz n + enter\n";
	}

	std::system("CLS");
	RysujSwiat();
	Czlowiek* Human = (Czlowiek*)GetHuman();

	if (Human == NULL) {
		std::cout << "GAME OVER";
		exit(1);
	}
	else {
		std::cout << "Niech czlowiek wykona ruch: " << endl;
		if (Human->GetUmiejetnoscAktywnaPrzez() > 0) std::cout << "aktywnosc aktywna przez:" << Human->GetUmiejetnoscAktywnaPrzez() << endl;
		if (Human->GetUmiejetnoscOdnawianaPrzez() > 0) std::cout << "aktywnosc odnawiana przez:" << Human->GetUmiejetnoscOdnawianaPrzez() << endl;
	}
	
}



void Swiat::SetPole(COORDINATES coor, Organizm* org) {
	this->plansza[coor.x][coor.y] = org;
}

Organizm* Swiat::GetPole(COORDINATES coor) {
	if (this == NULL) std::cout << "NULL";
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
		return o1->GetInicjatywa() > o2->GetInicjatywa();
	}
	return o1->GetWiek() > o2->GetWiek();
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

vector<Organizm*> Swiat::wezWszystkieOrganizmy(bool TylkoAktywne) {
	vector<Organizm*> res;
	for (int i = 0; i < szerokosc; i++) {
		for (int j = 0; j < wysokosc; j++) {
			COORDINATES coor{ i,j };
			if (TylkoAktywne == true) {
				if(GetPole(coor)->GetWykonalRuch() == false)
					res.push_back(GetPole(coor));
			}
			else
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




