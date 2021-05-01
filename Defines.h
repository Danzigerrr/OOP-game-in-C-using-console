#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <cstdlib>
#include <list>
#include <vector>
#include <string>
#include <fstream>
//#include <conio.h>
#include <algorithm>

#include <conio.h>
using namespace std;

#define GROUND '_'
#define INDEX 184698
#define CZLOWIEK 'H'
#define ILOSC_GATUNKOW 11 
#define UMIEJETNOSC_AKTYWNA 5 //tury
#define UMIEJETNOSC_ODNAWIANA 5 //tury
#define ILOSC_ORGANIZMU_NA_POCZATKU 2
//ANIMALS
#define WILK 'W'
#define OWCA 'O'
#define LIS 'L'
#define ZOLW 'Z'
#define ANTYLOPA 'A'

//PLANTS
#define TRAWA '_'
#define MLECZ '@' 
#define GUARANA '#'
#define WILCZEJAGODY '%' 
#define BARSZCZ '$'
			
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13
#define ESC 27

enum DIRECTION {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

struct COORDINATES {
	int x;
	int y;
};

class Swiat;

int KierunekRuchuCzlowieka = 0; //key input

