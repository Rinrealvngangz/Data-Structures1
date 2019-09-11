#include<iostream>
#include<conio.h>
#include<string.h>
#include<fstream>
#include<iomanip>
using namespace std;

#include"thuvien.h"
#include"menu.h"

void chaychuongtrinh();
int main() {

	chaychuongtrinh();

	return 0;
}


void chaychuongtrinh() {

	nhanvien NV[MAX];
	int n ;
	int menu;
	int somenu = 8;
	do {

		menu = chonmenu(somenu);
		xulymenu(menu,NV,n);

	} while (menu>0);


	_getch();
}