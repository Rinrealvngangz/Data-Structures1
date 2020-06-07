#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <string.h>
#include <queue>
#include <stack>

using namespace std;

#include "Common.h"
#include "Graph.h"
#include "thuvien.h"


int main()
{
	LableType lab;
	LableType l,u,v;
	char filename[] = "Text2.txt";
	char filesave[] = "save.txt";
	Graph g;
	g= OpenGraph(filename);
	DisplayMatrix(g);
	cout << "them 1 dinh"<<endl;
	cout << "Nhap dinh can them:";
	cin >> lab;
	cout << "ma tran ban dau :";
	DisplayMatrix(g);
	themMotDinh(g,lab);
	cout << "ma tran sau khi them dinh";
	DisplayMatrix(g);
	cout << "Tim thong tin cua 1 dinh\n";
	cout << "Nhap thong tin Dinh can tim :";
	cin >> l;
	
	if (timDinh(g, l) != -1)
	{
		int pos = timDinh(g, l);
		hienThiThongTinDinhTaiVitri(g, pos);
	}
	else
	cout << "khong ton tai dinh can tim";

	cout << "------------";
	cout << "\nKiem tra hai dinh u, v co ke nhau (co canh noi giua chung) hay khong";
	cout << "\nNhap dinh u:";
	cin >> u;
	cout << "\nNhap dinh v:";
	cin >> v;
	kiemTraHaiDinhkeNhau(g, u, v);
	cout << "------------";
	cout << "\nThem mot canh co trong so w noi 2 dinh u, v vao do thi\n";
	ThemCanhCoTrongSo(g, u, v);
	saveFile(g, filesave);
cout << "------------";
	cout << "Duyet do thi theo chieu rong dung queue\n";
	BFS_Loop(g, 0);
	cout << "\n------------\n";
	cout << "\nDuyen do thi theo chieu sau loop";
	DFS(g, 0);
	cout << "\nDuyet do thi chieu sau theo de quy ";
ResetFlags(g);
	DFS_Dequy(g, 0);
	//KT_LienThong(g);
	_getch();
	return 0;
}


