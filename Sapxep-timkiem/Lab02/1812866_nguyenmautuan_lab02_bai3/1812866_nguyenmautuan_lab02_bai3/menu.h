
void xuatmenu() {

	cout << "\n0: Thoat chuong trinh";
	cout << "\n1: Tao danh sach sinh vien";
	cout << "\n2: Xem danh sach sinh vien";
	cout << "\n3: Tim kiem theo ho ten";
	cout << "\n4: Tim kiem nam sinh";
	cout << "\n5: Tim kiem theo ho ten, nam sinh";
	cout << "\n6: Tim kiem theo ten va dia chi";
	cout << "\n7: Tim kiem nam sinh va luong";
	cout << "\n8: Tim kiem nhi phan theo ma nhan vien cho truoc";
}

int chonmenu(int somenu)
{

	int stt;
	for (; ;)
	{
		system("CLS");
		xuatmenu();
		cout << "\n\n\n(Chon chuc nang 1 de tao danh sach,truoc khi chon chuc nang khac)";
		cout << "\n\nChon so trong khoang(0,.." << somenu << ") stt:= ";
		cin >> stt;

		if (0 <= stt && stt <= somenu)
			break;
	}

	return stt;
}

void xulymenu(int menu,nhanvien NV[MAX], int &n)
{
	char maso[MAX];
	char diachi[MAX];
	int x;
	unsigned long int y;
	int nam;
	int kq;
	char* f = new char[MAX];
	char ho[MAX], ten[MAX];
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\n0 Thoat chuong trinh.";
		cout << "\n0: Thoat chuong trinh";
		exit(0);
		break;

	case 1:
		system("CLS");
		cout << "\n1: Tao danh sach sinh vien";
		do {
			cout << "\nNhap ten file:";
			cin >> f;
			kq = taodanhsachSV(f,NV,n);
			if (!kq)
			{
				cout << "\n Moi nhap lai....." << endl;
			}
		} while (!kq);
		break;
		
	case 2:
		system("CLS");
		cout << "\n2: Xem danh sach sinh vien";
		xuatDSSV(NV, n);
		break;
	case 3:
		system("CLS");
		cout << "\n3: Tim kiem theo ho, ten";
		
		cout << "\nNhap ho nv:";
		gets_s(ho, MAX);
		gets_s(ho, MAX);
		cout << "\nNhap ten nv:";
		gets_s(ten, MAX);
		timkiemho_ten(n, NV, ho, ten);
	
		break;
	case 4:
		system("CLS");
		cout << "\n4: Tim kiem nam sinh";
		cout << "\nNhap nam sinh nv:";
		cin >> nam;
		timkiemnamsinh(n, NV, nam);
		break;
	case 5:
		system("CLS");
		cout << "\n5: Tim kiem theo ho ten, nam sinh";
		cout << "\nNhap ho nv:";
		gets_s(ho, MAX);
		gets_s(ho, MAX);
		cout << "\nNhap ten nv:";
		gets_s(ten, MAX);
		cout << "\nNhap  X tim nam sinh :";
		cin >> x;
		timkiemho_ten_namsinh(n, NV, x, ho, ten);
		break;
	case 6:
		system("CLS");
		cout << "\n6: Tim kiem theo ten va dia chi";
		cout << "\nNhap dia chi:";
		gets_s(diachi, MAX);
		gets_s(diachi, MAX);
		cout << "\nNhap ten nv:";
		gets_s(ten, MAX);
		timkiemtheoten_diachi(n, NV, diachi,ten);
		
		break;
	case 7:
		system("CLS");
		cout << "\n7: Tim kiem nam sinh va luong";
		cout << "\nNhap X  :";
		cin >> x;
		cout << "\nNhap Y  :";
		cin >> y;
		timkiemnamsinh_luong(n, NV, x, y);
		break;
	case 8:
		system("CLS");
		cout << "\n8: Tim kiem nhi phan theo ma nhan vien cho truoc";
		cout << "\nNhap ma so nv:";
		gets_s(maso, MAX);
		gets_s(maso, MAX);
		timkiemnhiphan(n, NV,maso);
	
		break;

	}
	_getch();
}


