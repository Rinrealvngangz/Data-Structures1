#include<iostream>
#include<iomanip>
#include<conio.h>
#include<fstream>
#include<string.h>
using namespace std;

#include"thuvien.h"
#include"menu.h"

void chaychuongtrinh();

int main() {

	chaychuongtrinh();
	return 0;
}


void chaychuongtrinh()
{
	int somenu = 13;
	LISTNV l;
	int menu;
	do {
		menu = chonmenu(somenu);
		xulimenu(menu,l);

	} while (menu > 0);

	_getch();
}


