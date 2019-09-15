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

int taodanhsachSV(char* filename, nhanvien NV[MAX], int& n)
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

void xuat1NV(nhanvien& p)
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
		<< setw(10) << "MaSV"
		<< setw(9) << "Ho"
		<< setw(9) << "TLot"
		<< setw(10) << "Ten"
		<< setw(6) << "Ngay"
		<< setw(6) << "Thang"
		<< setw(6) << "Nam"
		<< setw(14) << "Dia chi"
		<< setw(8) << "Luong"
		<< ':';
}

void xuatDSSV(nhanvien NV[MAX], int& n)
{
	int i;
	xuatkengangdoi();
	xuattieude();
	xuatkengangdoi();
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


void hoanvi(nhanvien &p ,nhanvien &q)
{ 
	nhanvien t;

	t = p;
	p = q;
	q = t;
}
void chontructiep_tang_maNV(int &n, nhanvien NV[MAX])
{
	int i, j;
	int min;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		
			if (_strcmpi(NV[j].maSV, NV[min].maSV) < 0)

				min = j;
			hoanvi(NV[min], NV[i]);
		
	}
}


void chentructiep_tang_diachi(int& n, nhanvien NV[MAX])
{
	int i, j;
	char  x[MAX];
	int pos;
	
	for (i = 1; i < n; i++)
	{
	
		strcpy_s(x,NV[i].diachi);
		pos = i - 1;

		while ((pos >= 0) && (_strcmpi(NV[pos].diachi, x) > 0)) {

			strcpy_s(NV[pos + 1].diachi, NV[pos].diachi);
			pos--;
		}
		strcpy_s(NV[pos + 1].diachi,x);
	}
}

void doichotructiep_luong(int& n, nhanvien NV[MAX])
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		
			if (NV[j].luong > NV[i].luong)
				hoanvi(NV[i], NV[j]);
		
	}
}


void chennhiphan_giam_maNV(int& n, nhanvien NV[MAX])
{
	int i, j;
	int r, l, m;
	char  x[MAX];

	for (i = 1; i < n; i++)
	{
		l = 0;
		r = i-1;
		
		strcpy_s(x, NV[i].maSV);
		while (l <= r)
		{

			m = (r + l) / 2;
			if (_strcmpi(x, NV[m].maSV) < 0)
				r= m - 1;
			else
				l = m + 1;

		}
		for (j = r -1; j >= l; j--)
		
			strcpy_s(NV[j + 1].maSV, NV[j].maSV);
			strcpy_s(NV[l].maSV,x);
		
	}

}


void shift(nhanvien NV[MAX], int r, int l)
{
	int i, j;
	double x;

	i = l;
	j = (2 * i) + 1;

	x = NV[i].luong;
	while (j <= r) {

		if (j < r);// có hai phần tử liên đới
		if (NV[j].luong < NV[j + 1].luong)
		
			j = j + 1;
		if (NV[j].luong < x)
			return;
		else
		{
			NV[i].luong = NV[j].luong;
			i = j;
			j = (2 * i) + 1;
			NV[i].luong = x;
		}

	}

}

void createHeap(nhanvien NV[MAX], int n)
{
	int l;
	l = (n - 1) / 2;
	while (l >= 0)
	{
		shift(NV, n - 1, l);
		l =l - 1;
	}

}

void heapsort(nhanvien NV[MAX], int n)
{
	int r;
	createHeap(NV, n);
	r = n - 1;
	while (r > 0)
	{
		hoanvi(NV[0], NV[r]);
		r = r- 1;

		shift(NV, r, 0);
	}
}




