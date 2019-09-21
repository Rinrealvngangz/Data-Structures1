void xuatmenu() {
	cout << "\n=============He thong quan ly nhan vien===================";
	cout << "\n0: Thoat chuong trinh";
	cout << "\n1: Nhap danh sach nhan vien tu file";
	cout << "\n2: Xuat danh sach nhan vien";
	cout << "\n3: Tim theo ten nhan vien-tra ve nut cuoi cung(neu co";
	cout << "\n4: Tim nhan vien co luong cao nhat";
	cout << "\n5: Dem so nhan vien co tien luong >=x ";

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

void xulymenu(int menu, LISTNV &l)
{
	NODENV* kq;
	
	char filename[20]="dsnv.txt" ;
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
		cout << "\n1: Nhap danh sach nhan vien tu file";
		chuyen_taptin(l,filename);
		break;
	case 2:
		system("CLS");
		cout << "\n2: Xuat danh sach nhan vien";
		xuatlistNV(l);
		break;
	case 3:
		char ten[20];
		system("CLS");
		cout << "\n3: Tim theo ten nhan vien-tra ve nut cuoi cung(neu co)";
		cout << "\nNhap ten can tim:";
		cin >> ten;
		kq =timtenNV(l, ten);
		if (!kq)
		{
			cout << "\nKo co nhan vien ten "<< ten<< " trong DS";
		}
		else
		{
			cout << "\nThong tin Nhan vien co ten " << ten<< " la";
			cout << "\n";
			xuattieude();
			xuatkengangdoi();
			cout << "\n";
			xuat1NV(kq->info);
			xuatkengangdon();
		}
		
		break;
	case 4:
		double luong;
		NODENV* kq1;
		system("CLS");
		cout << "\n4: Tim nhan vien co luong cao nhat";
		 kq1=timNVluongcao(l);
		 if (kq1)
		 {
			 cout << "\nNhan vien co luong cao nhat la:\n";
			 xuattieude();
			 xuatkengangdoi();
			 xuat1NV(kq1->info);
			 xuatkengangdon();
		 }
		break;
	case 5:
		double x;
		double kq2;
		system("CLS");
		cout << "\n5: Dem so nhan vien co tien luong >=x ";
		cout << "\nNhap so luong X: ";
		cin >> x;
		kq2 = demNV_luong_caohonX(l, x);
		if (!kq2)
		{
			cout << "\nKhong co nhan vien co luong lon hon " << x;
		}
		else
		{
			cout << "\nCo " << kq2 << " nhan vien co luong lon hon " << x;
		}

		break;
	}
	_getch();
}
