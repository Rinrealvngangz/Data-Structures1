
typedef unsigned int Byte;

struct  ngaythangnam
{
	Byte ngay;
	Byte thang;
	Byte nam;
};

struct nhanvien
{

	char maNV[8];
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

struct  LISTNV
{
	NODENV *pHead;
	NODENV *pTail;

};


NODENV *getNODENV(Data x) 
{

	NODENV *p;
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


void createLIST(LISTNV &l)
{
	l.pHead = l.pTail = NULL;
}


//Them vao cuoi node
void AddTail(LISTNV &l,NODENV *p) 
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = p;
	}

	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
	 
}


void chuyenteptin(LISTNV &l, char *name)
{
	nhanvien nv;

	NODENV *p;
	ifstream in(name);
	if (!in) {
		cout << "\nloi mo file ! ";
		return ;
	}
	createLIST(l);
	char maNV[8];
	char Ho[11];
	char HoLot[11];
	char ten[11];
	Byte ngay, thang, nam;
	char Diachi[16];
	double luong;

	while (!in.eof())
	{
		in >> nv.maNV;
		in >>nv.Ho ;
		in >>nv.HoLot ;
		in >>nv.ten ;
		in >>nv.ntns.ngay ;
		in >> nv.ntns.thang;
		in >> nv.ntns.nam;
		in >> nv.Diachi;
		in >>nv.luong ;
		p = getNODENV(nv);
		if (p == NULL)
			break;
		AddTail(l, p);

	}
	cout << "\nChuyen tap tin thang cong";
	in.close();
	return;
}

void xuattieude() {
	cout << "\n";
	cout << setiosflags(ios::left) << ':' 
		 << setw(10)<<"MaNV"
		<< setw(9) << "Ho"
		<< setw(10) << "HoLot"
		<< setw(10) << "Ten"
		<< setw(6) << "Ngay"
		<< setw(6) << "Thang"
		<< setw(6) << "Nam"
		<< setw(14) << "Dia chi"
		<< setw(8) << "Luong"
		<<':';
	
}

void xuat1NV(nhanvien nv)
{
	cout << "\n";
	cout << setiosflags(ios::left) << ':'
		<< setw(10) << nv.maNV
		<< setw(9) << nv.Ho
		<< setw(10) << nv.HoLot
		<< setw(10) << nv.ten
		<< setw(6) << nv.ntns.ngay
		<< setw(6) << nv.ntns.thang
		<< setw(6) << nv.ntns.nam
		<< setw(14) << nv.Diachi
		<< setw(8) <<setprecision(0)<<setiosflags(ios::fixed)<<nv.luong
		<< ':';

}

void xuatlistNV(LISTNV l)
{
	NODENV *p;
	p = l.pHead;
	cout << "\n";
	xuattieude();
	
	while (p!=NULL)
	{
		xuat1NV(p->info);
		p = p->pNext;
	}
}

NODENV *timTenNV(LISTNV &l , char ten[10])
{
	NODENV* p=l.pHead;
	NODENV* vt = NULL;
	int dem = 0;
	int pos = 0;

	while (p != NULL)
	{
		if (_strcmpi(p->info.ten, ten) == 0)
		{
			vt = p;
			pos = dem; //vi tri pos
			
		}

		dem++;
		p = p->pNext;

	}

	if (pos == 0) 
	{

		cout << "\nMoi nhap lai ten";
	}
	else
	{
		cout << "\nNhan vien tai vi tri thu " << pos + 1 << " trong danh sach ";
	}

	return vt;
}

NODENV* Timluongcao(LISTNV& l) {

	NODENV* q = NULL;
	NODENV* p=l.pHead;
	double max;
	max = p->info.luong;
	while (p!=NULL)
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

void demluongNV_lonhonX(LISTNV l,double x)
{
	int dem = 0;
	int pos = 0;
	NODENV* p = l.pHead;
	NODENV* q = NULL;
	xuattieude();
	while (p!=NULL)
	{
		if (p->info.luong >= x)
		{
			dem++;
			q = p;
			xuat1NV(q->info);
		}
		p = p->pNext;
	}
	if (!dem)
	{
		cout << "\nKhong co nhan vien co luong hon " << x;
	}
	else
	{
		cout << "\nSo nhan vien co luong lon hon " << x << " la " << dem << " nhan vien";

	}
	
}

bool isEmptyList(LISTNV l)
{
	return l.pHead = NULL;
}

LISTNV xoa_NVcoDiachi_X(LISTNV& l, char Diachi[16])
{
	LISTNV kq;

	createLIST(kq);
	if (!isEmptyList(l))
	{
		NODENV* p, * node;
		p = l.pHead;

		while (p)
		{
			if (_strcmpi(p->info.Diachi, Diachi) != 0)
			{
				node = getNODENV(p->info);
				AddTail(kq, node);
				
			}
			p = p->pNext;
		}
		
	}
	return kq;

}

void RemoveList(LISTNV &l)
{
	NODENV* p=l.pHead;

	while (l.pHead != NULL)
	{
		p = l.pHead;
		l.pHead = p->pNext;
		delete p;
	}
	l.pTail = NULL;
}



NODENV* huy_node_NV_dau(LISTNV& l, char ten[20])
{

	NODENV* p = l.pHead;

	while (p != NULL)
	{
		if (_strcmpi(p->info.ten, ten) == 0)
			return p;
		p = p->pNext;
	}

	
	return p;
}

LISTNV xoa_NV_first_X(LISTNV& l, NODENV*node)
{
	LISTNV list;

	createLIST(list);
	if (!isEmptyList(l))
	{
		NODENV* p, *newnode;
		p = l.pHead;

		while (p)
		{
			if (p !=node)
			{
				newnode = getNODENV(p->info);
				AddTail(list, newnode);

			}
			p = p->pNext;
		}

	}
	return list;

}

void hoanvi(nhanvien  &a,  nhanvien &b)
{
	nhanvien t;
	t = a;
	a = b;
	b = t;
}
//doi cho truc tiep
void interchangesort(LISTNV l)
{
	NODENV* i, *j;
	for( i =l.pHead; i!=l.pTail;i=i->pNext )
		for (j = i->pNext; j != NULL; j=j->pNext)
		
			if (_strcmpi(j->info.ten , i->info.ten)<0)
			
				hoanvi( j->info, i->info );
			
		
}

void chontructiep(LISTNV l) {

	NODENV* i, * j, *min;
	for (i = l.pHead; i != l.pTail; i = i->pNext)
	{
		min = i;
		for (j = i->pNext; j != NULL; j = j->pNext)
			if (min->info.luong > j->info.luong)
				min = j;
		hoanvi(i->info, min->info);
	}
	
}

void quicksort(LISTNV &l)
{
	NODENV* x, * p;
	LISTNV l1, l2;

	if (l.pHead == NULL)
		return;
	else
	{
		if (l.pHead == l.pTail)
			return;
		createLIST(l1);
		createLIST(l2);
		x = l.pHead;
		l.pHead = x->pNext;
		while (l.pHead !=NULL)
		{
			p = l.pHead;
			l.pHead = p->pNext;
			p->pNext = NULL;
			if (p->info.luong <= x->info.luong)
				AddTail(l1, p);
			else
				AddTail(l2, p);
		}
		quicksort(l1);
		quicksort(l2);
		if (l1.pHead != NULL)
		{
			l.pHead = l1.pHead;
			l1.pTail->pNext = x;
		}
		else
			l.pHead = x;
		if (l2.pHead != NULL)
		{
			x->pNext = l2.pHead;
			l.pTail = l2.pTail;
		}
		else
			l.pTail = x;
	}

}


NODENV* timTenNV_node_first(LISTNV& l, char ten[10])
{
	NODENV* p = l.pHead;
	NODENV* vt = NULL;
	int dem = 0;
	int pos = 0;

	while (p != NULL)
	{
		if (_strcmpi(p->info.ten, ten) == 0)
		{

			pos = dem; //vi tri pos
			vt = p;
			break;
		
			
			

		}

		dem++;
		p = p->pNext;

	}

	if (pos == 0)
	{

		cout << "\nMoi nhap lai ten";
	}
	else
	{
		cout << "\nNhan vien tai vi tri thu " << pos + 1 << " trong danh sach ";
	}

	return vt;
}

void swap1(NODENV* p, NODENV* q)
{
	int t;
	t = p->info.luong;
	p->info.luong = q->info.luong;
	q->info.luong = t;

}

void noibot(LISTNV& l)
{
   int i;
	do {
		
		i = 0;
		NODENV* p, * q;
		p = l.pHead;
		q = NULL;
		while (p->pNext != q)
		{
			if (p->info.luong > p->pNext->info.luong)
			{
				swap1(p, p->pNext);
				i = 1;
			}
			p = p->pNext;
		}
		q = p;

	} while (i);
	
}