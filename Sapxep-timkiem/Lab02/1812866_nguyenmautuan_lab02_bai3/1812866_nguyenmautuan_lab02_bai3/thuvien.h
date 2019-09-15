
#define MAX 100
#define KENGANGDOI '='
#define KENGANGDON '-'

typedef unsigned short int Byte;


struct ngaythangnamsinh
{
	Byte ngay;
	Byte thang;
	unsigned int nam;
};

struct nhanvien {

	char maSV[8];
	char Ho[11];
	char tenlot[11];
	char ten[11];
	ngaythangnamsinh ntns;
	char diachi[16];
	double luong;

};

int taodanhsachSV(char* filename, nhanvien NV[MAX], int &n)
{
	ifstream in(filename);

	if (!in) {
		cout << "\n Loi tao file !";
		return 0;
	}
	char maNV[8];
	char Ho[11];
	char tenlot[11];
	char ten[11];
	int ngay, thang, nam;
	char diachi[16];
	double luong;

	n = 0;

	in >> maNV; strcpy_s(NV[n].maSV, maNV);
	in >> Ho; strcpy_s(NV[n].Ho, Ho);
	in >> tenlot; strcpy_s(NV[n].tenlot, tenlot);
	in >> ten; strcpy_s(NV[n].ten, ten);
	in >> ngay; NV[n].ntns.ngay = ngay;
	in >> thang; NV[n].ntns.thang = thang;
	in >> nam; NV[n].ntns.nam = nam;
	in >> diachi; strcpy_s(NV[n].diachi, diachi);
	in >> luong; NV[n].luong = luong;

	while (!in.eof()) {
		n++;
		in >> maNV; strcpy_s(NV[n].maSV, maNV);
		in >> Ho; strcpy_s(NV[n].Ho, Ho);
		in >> tenlot; strcpy_s(NV[n].tenlot, tenlot);
		in >> ten; strcpy_s(NV[n].ten, ten);
		in >> ngay; NV[n].ntns.ngay = ngay;
		in >> thang; NV[n].ntns.thang = thang;
		in >> nam; NV[n].ntns.nam = nam;
		in >> diachi; strcpy_s(NV[n].diachi, diachi);
		in >> luong; NV[n].luong = luong;

	}
	in.close();
}

void xuatkengangdoi() {

	cout << '\n';
	cout << setiosflags(ios::left) << ':';

	for (int i = 0; i < 78; i++)
	
		cout << KENGANGDOI;
	cout << ':';
	
}
void xuatkengangdon() {

	cout << '\n';
	cout << setiosflags(ios::left) << ':';

	for (int i = 0; i < 78; i++)

		cout << KENGANGDON;
	cout << ':';

}

void xuat1NV( nhanvien &p)
{
	cout << "\n";
	cout << setiosflags(ios::left) <<
		':'
		<< setw(10) << p.maSV
		<< setw(9) << p.Ho
		<< setw(9) << p.tenlot
		<< setw(10) << p.ten
		<< setw(6) << p.ntns.ngay
		<< setw(6) << p.ntns.thang
		<< setw(6) << p.ntns.nam
		<< setw(14) << p.diachi
		<< setw(8) << p.luong << setprecision(8)
		<< ':';
	cout << endl;
}

void xuattieude() {

	cout << "\n";
	cout << setiosflags(ios::left) <<
		':'
		<< setw(10) <<"MaSV"
		<< setw(9) <<"Ho"
		<< setw(9) <<"TLot"
		<< setw(10) <<"Ten"
		<< setw(6) << "Ngay"
		<< setw(6) << "Thang"
		<< setw(6) << "Nam"
		<< setw(14) << "Dia chi"
		<< setw(8) << "Luong"
		<< ':';
}

void xuatDSSV(nhanvien NV[MAX], int &n)
{
	int i;
	xuatkengangdoi();
	xuattieude();
	cout << "\n";
	for (i = 0; i < n; i++)
	{
		xuat1NV(NV[i]);
		if ((i + 1) % 5 == 0)
		{
			xuatkengangdon();
		}
	
	}
	xuatkengangdoi();
}

void timkiemho_ten(int &n, nhanvien NV[MAX],char ho[MAX],char ten[MAX])
{
	int i;
	int dem = 0;
	for (i = 0; i < n; i++)
	{
		if (_strcmpi(NV[i].ten, ten) == 0 || _strcmpi(NV[i].Ho,ho)==0) 
			dem++;

	}

	if (!dem)
	{
		cout << "\nKhong co nhan vien co ten"<<ten<< "va ho "<<ho<<  " trong danh sach";
	}

	else
	{
		cout << "\nSo nhan vien co trong DS la " << dem <<" nhan vien" ;
		xuatkengangdoi();
		xuattieude();
		for (i = 0; i < n; i++)
		{
			
			if (_strcmpi(NV[i].ten, ten) == 0 || _strcmpi(NV[i].Ho, ho) == 0)
				xuat1NV(NV[i]);
		}
		xuatkengangdoi();
	}
}

void timkiemnamsinh(int &n, nhanvien NV[MAX], int nam) {

	int i ;
	int dem = 0;
	for (i = 0; i < n; i++)
	{
	
		if (NV[i].ntns.nam == nam)
			dem++;
	}
	if (!dem)
	{
		cout << "\nKhong co nhan vien co nam sinh "<<nam <<"trong danh sach";
	}

	else
	{
		cout << "\nSo nhan vien co trong DS la " << dem << " nhan vien";
		xuatkengangdoi();
		xuattieude();
		for (i = 0; i < n; i++)
		{

			if (NV[i].ntns.nam == nam)
				xuat1NV(NV[i]);
		}
		xuatkengangdoi();
	}
}

void timkiemho_ten_namsinh(int &n, nhanvien NV[MAX], int x, char ho[MAX],char ten[MAX])
{
	

	int i;
	int dem = 0;
	for (i = 0; i < n; i++)
	{

		if (NV[i].ntns.nam <x ||_strcmpi(NV[i].ten, ten) == 0 || _strcmpi(NV[i].Ho, ho) == 0)
			dem++;
	}
	if (!dem)
	{
		cout << "\nKhong co nhan vien co ten" << ten << "va ho " << ho << " va co nam sinh be hon " << x << "trong danh sach";
	}

	else
	{
		cout << "\nSo nhan vien co trong DS la " << dem << " nhan vien";
		xuatkengangdoi();
		xuattieude();
		for (i = 0; i < n; i++)
		{

			if (NV[i].ntns.nam < x || _strcmpi(NV[i].ten, ten) == 0 || _strcmpi(NV[i].Ho, ho) == 0)
				xuat1NV(NV[i]);
		}
		xuatkengangdoi();
	}
}

void timkiemtheoten_diachi(int &n, nhanvien NV[MAX], char diachi[MAX],char ten[MAX])
{

	int i;
	int dem = 0;
	xuatkengangdoi();
	xuattieude();
	for (i = 0; i < n; i++)
		
		if (_strcmpi(NV[i].diachi, diachi) == 0 && _strcmpi(NV[i].ten, ten) == 0)
			xuat1NV(NV[i]);
	
	xuatkengangdoi();
	
}

void timkiemnamsinh_luong(int& n, nhanvien NV[MAX],unsigned long int x, int y)
{
	int i;
	int dem = 0;
	xuatkengangdoi();
	xuattieude();
	for (i = 0; i < n; i++)

		if (NV[i].luong >= x && NV[i].ntns.nam <=y )
			xuat1NV(NV[i]);

	xuatkengangdoi();
}

//void hoanvi(nhanvien &p ,nhanvien &q)
//{ 
//	nhanvien t;
//
//	t = p;
//	p = q;
//	q = t;
//}


//void sapxep_maso(int& n, nhanvien NV[MAX])
//{
//	int i, j;
//
//	for (i = 0; i < n - 1; i++)
//	{
//		for (j = i + 1; j < n; j++)
//		{
//			if (_strcmpi(NV[i].maSV, NV[j].maSV) > 0)
//				hoanvi(NV[i], NV[j]);
//		}
//	}
//
//
//}
void timkiemnhiphan(int &n, nhanvien NV[MAX], char maso[MAX])
{
	int kq;
	int dem = 0;
	int r, m, l;
	int i;
	r = n-1;
	l = 0;
	do
	{
		m = (r + l) / 2;
		if (_strcmpi(NV[m].maSV, maso) == 0)
		{	
			dem++;
		
		}
		else if (_strcmpi(NV[m].maSV, maso) < 0)

			l = m + 1;
		else
			r = m - 1;
	} while (l >= r);

	xuatkengangdoi();
	xuattieude();
	for (i = 0; i < n; i++)
	
		if (_strcmpi(NV[m].maSV, maso) == 0)
			xuat1NV(NV[i]);
	
	xuatkengangdoi();


}