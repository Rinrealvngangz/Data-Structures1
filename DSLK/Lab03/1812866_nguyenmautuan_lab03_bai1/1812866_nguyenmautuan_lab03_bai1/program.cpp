#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
#include "thuvien.h"
#include "menu.h"
void chaychuongtrinh();
int main()
{

	chaychuongtrinh();
	return 1;
}

void chaychuongtrinh() {
	LIST l;
	int menu;
	int soMenu = 15;
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu,l);
	} while (menu > 0);

	_getch();


}