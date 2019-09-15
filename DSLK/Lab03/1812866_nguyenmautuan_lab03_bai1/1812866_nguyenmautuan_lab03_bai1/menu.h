void XuatMenu()
{
	cout << "\n==============He thong chuc nang=========================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Nhap DS lien ket file";
	cout << "\n2. Xuat du lieu";
	cout << "\n3. Tinh tong cac phan tu trong DS";
	cout << "\n4. Tim phan tu lon nhat trong DS";
	cout << "\n5. TimX-Tra ve vi tri nut dau tien neu co ";
	cout << "\n6. TimX-Tra ve nut cuoi cung neu co";
	cout << "\n7. Chen X vao dau danh sach";
	cout << "\n8. Chen X vao cuoi danh sach";
	cout << "\n9. Chen X sau sau nut co du lieu Y trong DS";
	cout << "\n10. Huy nut dau";
	cout << "\n11. Huy nut cuoi";
	cout << "\n12. Huy dau tien co du lieu x";
	cout << "\n13. Huy toan bo danh sach";
	cout << "\n14. Sap DS tang bang phuong phap chon truc tiep(Hoan doi du lieu)";
	cout << "\n15. Sap DS tang bang phuong phap chon truc tiep(Hoan doi moi lien ket)";
}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("CLS");
		XuatMenu();
		cout << "\nNhap 1 so khong khoang [0,..," << soMenu << "] de chon chuc nang, stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;

	}
	return stt;
}



void XuLyMenu(int menu, LIST& l)

{
	Data x, y;


	char filename[20] = "mang.txt";
	int kq;
	int a;
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\n0. Thoat khoi chuong trinh\n";
		exit(0);
		break;
	case 1:
		system("CLS");
		cout << "\n1. Nhap DS lien ket file\n";
		createList(l);
		NhapDS_File(l, filename);
		xuatDS(l);
		break;
	case 2:
		cout << "\n2. Xuat du lieu";
		cout << "\nDanh sach tu file:\n";
		xuatDS(l);
		break;
	case 3:
		cout << "\n3. Tinh tong cac phan tu trong DS";
		kq = tinhtong_phantu_Ds(l);
		cout << "\nTong cac phan  tu  : " << kq;
		break;
	case 4:
		cout << "\n4. Tim phan tu lon nhat trong DS";
		kq = timMAX_DS(l);
		cout << "\nphan tu lon nhat la : " << kq;
		break;
	case 5:

		cout << "\n5. TimX-Tra ve vi tri nut dau tien neu co ";
		cout << "\n DS hien hanh:\n";
		xuatDS(l);
		cout << "\nNhap phan tu  A can tim :";
		cin >> a;
		timvtxfirts(l, a);
		break;
	case 6:
		int x;
		cout << "\n6. TimX-Tra ve nut cuoi cung neu co";
		cout << "\n DS hien hanh:\n";
		xuatDS(l);
		cout << "\nNhap phan tu  A can tim :";
		cin >> x;
		kq = timvt_X_last(l, x);
		cout << "\nVi tri a can tim la: " << kq;

		break;
	case 7:
		system("CLS");
		cout << "\n7. Chen X vao dau danh sach";
		cout << "\n DS hien hanh:\n";
		xuatDS(l);
		cout << "\nNhap phan tu  X can chen :";
		cin >> x;
		chenXvaodauDS(l, x);
		cout << "\n DS sau khi chen:\n";
		xuatDS(l);
		break;
	case 8:
		cout << "\n8. Chen X vao cuoi danh sach";
		cout << "\n DS hien hanh:\n";
		xuatDS(l);
		cout << "\nNhap phan tu  X can chen :";
		cin >> x;
		chenXvaocuoiDS(l, x);
		cout << "\n DS sau khi chen:\n";
		xuatDS(l);
		break;
	case 9:
		cout << "\n9. Chen X sau sau nut co du lieu Y trong DS";
		cout << "\n DS hien hanh:\n";
		xuatDS(l);
		cout << "\nNhap phan tu  X can chen vao mang :";
		cin >> x;
		cout << "\nNhap phan tu Y trong mang muon chen vao: ";
		cin >> y;
		chenXvaoY(l, x, y);
		cout << "\n DS sau khi chen:\n";
		xuatDS(l);
		break;

	case 10:
		cout << "\n10. Huy nut dau";
		cout << "\n DS hien hanh:\n";
		xuatDS(l);
		huydauDS(l);
		cout << "\n DS sau khi xoa dau:\n";
		xuatDS(l);
		break;

	case 11:
		cout << "\n11. Huy nut cuoi";
		cout << "\n DS hien hanh:\n";
		xuatDS(l);
		huycuoiDS(l);
		cout << "\n DS sau khi xoa cuoi:\n";
		xuatDS(l);
	case 12:
		cout << "\n12. Huy dau tien co du lieu x";
		cout << "\n DS hien hanh:\n";
		xuatDS(l);
		cout << "\nNhap X can xoa";
		cin >> x;
	   huy_x_DS(l, x);
		cout << "\n DS sau khi xoa cuoi:\n";
		xuatDS(l);
		break;
	case 13:
		cout << "\n13. Huy toan bo danh sach";
		cout << "\n DS hien hanh:\n";
		xuatDS(l);
		cout << "\nDS khi  Xoa toan Bo du lieu\n";
		xoa_DS(l);
		cout << "\nDs rong ";
		break;
	case 14:
		cout << "\n DS hien hanh:\n";
		xuatDS(l);
		sapxeptang_chontructiep_dulieu(l);
		cout << "\nDS sau khi sap xep tang:";
		xuatDS(l);
		break;
	case 15:
		cout << "\n DS hien hanh:\n";
		xuatDS(l);
		listselectionsort2(l);
		cout << "\nDS sau khi sap xep tang:";
		xuatDS(l);
		break;
}
	_getch();
}
