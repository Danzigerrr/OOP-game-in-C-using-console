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
using namespace std;

#define GROUND '_'
#define INDEX 184698
#define CZLOWIEK 'H'
#define ILOSC_GATUNKOW 11 

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
			
#define ARROW_UP 72		
#define ARROW_DOWN 80
#define ARROW_LEFT 75
#define ARROW_RIGHT 77

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

//char input[10] = {};

