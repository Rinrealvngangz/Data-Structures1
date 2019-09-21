#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <iomanip>

using namespace std;

#include "thuvien.h"
#include"menu.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 0;
}

void ChayChuongTrinh() {
	
	LISTNV l;
	
	int menu;
	int somenu = 5;
	do {

		menu = chonmenu(somenu);
		xulymenu(menu,l);

	} while (menu > 0);


	_getch();
}
