#define KENGANGDOI '='
#define KENGANGDON '-'

typedef unsigned int Byte;


struct ngaythangnam {

	Byte ngay;
	Byte thang;
	int nam;

};

struct nhanvien
{
	char MaNV[8];
	char Ho[11];
	char HoLot[11];
	char ten[11];
	ngaythangnam ntns;
	char Diachi[16];
	double luong;
};
typedef nhanvien Data;
struct tagnodenhanvien
{
	Data info;
	tagnodenhanvien* pNext;
};

typedef tagnodenhanvien NODENV;

struct LISTNV
{
	NODENV* pHead;
	NODENV* pTail;

};

NODENV* getNODENV( Data x)
{
	NODENV* p;
	p = new NODENV;

	if (p == NULL)
	{
		cout << "\nLoi cap phat bo nho";
		return NULL;
	}
	p->info = x;
	p->pNext = NULL;
	return p;
}
void createLIST(LISTNV &l) {

	l.pHead = l.pTail = NULL;
}


void AddTail(LISTNV& l, NODENV* p)
{

	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}

}

void chuyen_taptin(LISTNV &l, char* filename)
{
	nhanvien nv;
	NODENV* p;
	ifstream in(filename);

	if (!in)
	{
		cout << "\nLoi chuyen tap tin";
		return;
	}
	
	createLIST(l);

	char MaNV[8];
	char Ho[11];
	char HoLot[11];
	char ten[11];
	Byte ngay, thang;
	int nam;
	char Diachi[16];
	double luong;

	while (!in.eof())
	{
		
		in >> nv.MaNV;
		in >> nv.Ho;
		in >> nv.HoLot; 
		in >> nv.ten; 
		in >> nv.ntns.ngay;
		in >> nv.ntns.thang;
		in >> nv.ntns.nam;
		in >> nv.Diachi;
		in >> nv.luong; 
		p = getNODENV(nv);
		if (p == NULL) 
			break;
			AddTail(l, p);
		
	}
	cout << "\nChuyen tap tin thanh cong";
	in.close();
	return;

}

void xuatkengangdoi()
{
	cout << "\n";
	cout << setiosflags(ios::left)<<':';
	for (int i = 0; i < 76; i++)
	
		cout << KENGANGDOI;
		cout << ':';

}
void xuatkengangdon()
{
	cout << "\n";
	cout << setiosflags(ios::left) << ':';
	for (int i = 0; i < 76; i++)
	
		cout << KENGANGDON;
		cout << ':';

}

void xuattieude()
{
	cout << "\n";
	cout << setiosflags(ios::left) << ':'
		<< setw(10) << "MaNV"
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

void xuat1NV(nhanvien nv)
{
	cout << "\n";
	cout << setiosflags(ios::left) << ':'
		<< setw(10) << nv.MaNV
		<< setw(9) << nv.Ho
		<< setw(9) << nv.HoLot
		<< setw(10) << nv.ten
		<< setw(6) << nv.ntns.ngay
		<< setw(6) << nv.ntns.thang
		<< setw(6) << nv.ntns.nam
		<< setw(14) << nv.Diachi
		<< setw(8) << setprecision(0) << setiosflags(ios::fixed) << nv.luong
		<< ':';


}

void xuatlistNV(LISTNV l)
{
	NODENV* p;
	p = l.pHead;
	cout << "\n";
	xuattieude();
	xuatkengangdoi();
		while (p != NULL)
		{
			xuat1NV(p->info);
			p = p->pNext;
		}
		xuatkengangdon();

}
NODENV* timtenNV(LISTNV l, char ten[10])
{
	
	NODENV* p = l.pHead;
	NODENV* vt=NULL;
	int dem = 0;
	int pos = 0;
	char tenmoi[20];
	while (p != NULL)
	{
		if (_strcmpi(p->info.ten, ten) == 0)
		{
			vt = p;
			pos = dem;
		}
		dem++;
		p = p->pNext;
	}
	if (pos==0)
	{
		cout << "\nMoi nhap lai ten";
	}
	else
	{
		cout << "\nNhan vien nam vi tri thu " << pos+1 <<" trong DS";
	}
	return vt;

}


 NODENV*  timNVluongcao(LISTNV l)
{
	 NODENV* q=NULL;
	double max;
	NODENV* p;
	p = l.pHead;
	max = p->info.luong;// vt 0 la max

	while (p != NULL)
	{
		if (max < p->info.luong)
		{
			max = p->info.luong;
			q = p;
		}
		p = p->pNext;

	}
	return q;
}

 double demNV_luong_caohonX(LISTNV l,double x)
 {
	 
	 NODENV* p;
	 p = l.pHead;
	 int dem = 0;
	 while (p != NULL)
	 {
		 if (p->info.luong > x)
		 {
			 dem++;
		 }

		 p = p->pNext;
	 }
	

	 return dem;
 }