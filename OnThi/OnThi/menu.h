void xuatmenu() {

	cout << "\n==========================HE THONG QUAN LY NHAN VIEN=========================";
	cout << "\n0: Thoat chuong trinh";
	cout << "\n1: Nhap danh sach tu file";
	cout << "\n2: Xuat danh sach nhan vien";
	cout << "\n3: Tim theo ten nhan vien-tra ve nut cuoi cung(neu co";
	cout << "\n4: Tim nhan vien luong cao nhat";
	cout << "\n5: Dem so nhan vien co luong lon hon x";
	cout << "\n6: Huy toan bo nhan vien co dia chi x trong danh sach";
	cout << "\n7: Xoa toan bo ds";
	cout << "\n8: Hut nhan vien dau tien co ten X";
	cout << "\n9:Sap xep tang ten nhan vien bang phuong phap doi cho  truc tiep";
	cout << "\n10:Sap xep tang luong vien bang phuong phap chon truc tiep";
	cout << "\n11:Sap xep tang luong vien bang phuong quick sort";
	cout << "\n12: Tim theo ten nhan vien-tra ve nut dau tien";
	cout << "\n13:Sap xep tang luong vien bang phuong noi bot";
	
}

int chonmenu(int somenu) {

	int stt;
	for (; ;) {
		system("CLS");
		xuatmenu();
		cout << "\n\nChon chuc nang trong khoang(0...." << somenu << ") stt:=";
		cin >> stt;

		if (0 <= stt && stt <= somenu)
			break;
	}

	return stt;
}

void xulimenu(int menu, LISTNV& l)
{
	int kq2;
	LISTNV kq1;
	NODENV* kq;
	char ten[20];
	char name[10];//="dsnv.txt";
	double x;
	switch (menu)
	{
	case 0:
		cout << "\n0: Thoat chuong trinh";
		exit(0);
		break;
	case 1:
		system("CLS");
		cout << "\n1: Nhap danh sach tu file";
		cout << "\nNhap ten file: ";
		cin >> name;
		chuyenteptin(l, name);

		break;
	case 2:
		system("CLS");
		cout << "\n2: Xuat danh sach nhan vien";
		xuatlistNV(l);


		break;
	case 3:
		system("CLS");
		cout << "\n3: Tim theo ten nhan vien-tra ve nut cuoi cung(neu co";
		cout << "\nNhap ten nhan vien :";
		cin >> ten;
		kq = timTenNV(l, ten);
		if (!kq)
		{
			cout << "\nKhong co nhan vien" << ten << "can tim trong ds ";

		}
		else
		{
			cout << "\nNhan vien " << ten << "la";
			xuattieude();
			xuat1NV(kq->info);
		}

		break;

	case 4:
		system("CLS");
		cout << "\n4:Tim nhan vien luong cao nhat";
		kq = Timluongcao(l);
		cout << "\nNhan vien co luong co nhat la :";
		xuat1NV(kq->info);
		break;
	case 5:

		system("CLS");
		cout << "\n5: Dem so nhan vien co luong lon hon x";
		cout << "\nNhap luong :";
		cin >> x;
		demluongNV_lonhonX(l, x);
		break;
	case 6:

		char Diachi[16];
		system("CLS");
		cout << "\n6:Huy toan bo nhan vien co dia chi x trong danh sach";
		cout << "\nDanh sach nhan vien  ";
		xuatlistNV(l);
		cout << "\nNhap dia chi can xoa: ";
		cin >> Diachi;
		kq1 = xoa_NVcoDiachi_X(l, Diachi);
		cout << "\nDanh sach sau khi xoa dia chi ";
		xuatlistNV(kq1);
		break;
	case 7:	cout << "\nXoa toan bo ds";
		RemoveList(l);
		cout << "\nDS rong";
		break;
	case 8:	cout << "\n8: Hut nhan vien dau tien co ten X";
		cout << "\nDanh sach nhan vien  ";
		xuatlistNV(l);
		cout << "\nNhap ten nhan vien can xoa: ";
		cin >> ten;
		kq = huy_node_NV_dau(l, ten);
		if (kq)
		{
			cout << "\nDanh sach sau khi  co ten " << ten << " can xoa la:";
			kq1 = xoa_NV_first_X(l, kq);
			xuatlistNV(kq1);
		}
		else
		{
			cout << "\nKo co ten nhan vien can xoa";
		}
		break;
	case 9:
		cout << "\n9:Sap xep tang luong nhan vien bang phuong phap doi cho  truc tiep";
		cout << "\nDanh sach nhan vien  ";
		xuatlistNV(l);
		interchangesort(l);
		cout << "\nDanh sach nhan vien sau khi sap tang theo ten nhan vien";
		xuatlistNV(l);
		break;
	
	case 10:
		cout << "\n10:Sap xep tang luong vien bang phuong phap chon truc tiep";
		cout << "\nDanh sach nhan vien  ";
		xuatlistNV(l);
		chontructiep(l);
		cout << "\nDanh sach nhan vien sau khi sap tang luong";
		xuatlistNV(l);
		break;
	case 11:
		cout << "\n11:Sap xep tang luong vien bang phuong quick sort";
		cout << "\nDanh sach nhan vien  ";
		xuatlistNV(l);
		quicksort(l);
		cout << "\nDanh sach nhan vien sau khi sap tang luong quick sort";
		xuatlistNV(l);
		break;
	case 12 :
		cout << "\n12: Tim theo ten nhan vien-tra ve nut dau tien";
		cout << "\nNhap ten nhan vien :";
		cin >> ten;
		kq = timTenNV_node_first(l, ten);
		if (!kq)
		{
			cout << "\nKhong co nhan vien" << ten << "can tim trong ds ";

		}
		else
		{
			cout << "\nNhan vien " << ten << "la";
			xuattieude();
			xuat1NV(kq->info);
		}
		break;
	case 13:
		cout << "\n13:Sap xep tang luong vien bang phuong noi bot";
		cout << "\nDanh sach nhan vien  ";
		xuatlistNV(l);
		noibot(l);
		cout << "\nDanh sach nhan vien sau khi sap tang luong noi bot";
		xuatlistNV(l);
		break;


}
	_getch();
}