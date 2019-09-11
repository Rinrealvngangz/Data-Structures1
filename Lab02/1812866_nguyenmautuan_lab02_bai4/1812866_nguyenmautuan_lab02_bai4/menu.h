void xuatmenu() {

	cout << "\n0: Thoat chuong trinh";
	cout << "\n1: Tao danh sach sinh vien";
	cout << "\n2: Xem danh sach sinh vien";
	cout << "\n3: Dung thuat giai chon truc tiep sap DS tang maNV";
	cout << "\n4: Dung thuat giai chen truc tiep sap DS tang dan theo dia chi";
	cout << "\n5: Dung thuat giai doi cho truc tiep sap DS giam theo luong ";
	cout << "\n6: Dung thuat giai chen nhi phan sap DS giam dan theo maNV";
	cout << "\n7: Dung thuat giai heap sort sap DS tang dan theo luong";
	
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

void xulymenu(int menu, nhanvien NV[MAX], int& n)
{
	char* f = new char[MAX];
	int kq;
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
			kq = taodanhsachSV(f, NV, n);
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
		cout << "\n3: Dung thuat giai chon truc tiep sap DS tang maNV";
		cout << "\nDanh sach hien hanh :";
		xuatDSSV(NV, n);
		chontructiep_tang_maNV(n, NV);
		cout << "\nDs sau khi sap:";
		xuatDSSV(NV, n);
		break;
	case 4:
		cout << "\n4: Dung thuat giai chen truc tiep sap DS tang dan theo dia chi";
		cout << "\nDanh sach hien hanh :";
		xuatDSSV(NV, n);
		chentructiep_tang_diachi(n, NV);
		cout << "\nDs sau khi sap:";
		xuatDSSV(NV, n);
		break;
	case 5:
		cout << "\n5: Dung thuat giai doi cho truc tiep sap DS giam theo luong ";
		cout << "\nDanh sach hien hanh :";
		xuatDSSV(NV, n);
		doichotructiep_luong(n, NV);
		cout << "\nDs sau khi sap:";
		xuatDSSV(NV, n);
		break;
	case 6:
		cout << "\n6: Dung thuat giai chen nhi phan sap DS giam dan theo maNV";
		cout << "\nDanh sach hien hanh :";
		xuatDSSV(NV, n);
		chennhiphan_giam_maNV(n, NV);
		cout << "\nDs sau khi sap:";
		xuatDSSV(NV, n);
		break;
	case 7:
		cout << "\n7: Dung thuat giai heap sort sap DS tang dan theo luong";
		cout << "\nDanh sach hien hanh :";
		xuatDSSV(NV, n);
			heapsort(NV,n);
		cout << "\nDs sau khi sap:";
		xuatDSSV(NV, n);
		break;

	}
	_getch();
}