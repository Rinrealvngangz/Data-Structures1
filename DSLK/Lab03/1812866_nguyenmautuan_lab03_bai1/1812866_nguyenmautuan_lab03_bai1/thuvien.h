
typedef int Data;
struct tagNode
{
	Data infor;

	tagNode* pNext;

};
typedef tagNode NODE;
struct LIST
{
	NODE* pHead;
	NODE* pTail;

};

NODE* getnode(Data x)
{
	NODE* p;
	p = new NODE;

	if (p == NULL)
	{
		cout << "\nLoi cap phat bo nho";
		return NULL;
	}

	p->infor = x;
	p->pNext = NULL;

	return p;
}

void createList(LIST &l)
{

	l.pHead = l.pTail = NULL;

}

void AddTail(LIST &l, NODE*p)
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

void NhapDS_File(LIST &l, char* filename)

{
	Data x;
	int n;
	NODE*p;
	ifstream in(filename);

	if (!in)
	{
		cout << "\nLoi mo file";
	}
	in >> n;

	for (int i=0; i < n; i++)
	{
		in >> x;
		p= getnode(x);
		if (p == NULL)
			break;
		AddTail(l, p);
	}

}

int xuatDS(LIST l)
{

	if (l.pHead == NULL)
	{
		cout<<"\nMang rong";
		return 0;
	}
	NODE*p = l.pHead;
	while (p != NULL)
	{
		cout << p->infor << "\t";
		p = p->pNext;
	}

}
int tinhtong_phantu_Ds(LIST l)
{
	int sum = 0;
	NODE* p = l.pHead;
	while (p!=NULL)
	{
		sum += p->infor;
		p = p->pNext;

	}
	return sum;
}

int timMAX_DS(LIST l)
{
	int max;
	NODE* p = l.pHead;
	max = p->infor;
	while (p != NULL)
	{
		if (max < p->infor)
		
			max = p->infor;
		
		p = p->pNext;

	}
	return max;
}


int timvtxfirts(LIST l,Data a)
{
	int i = 0;
	NODE* p;
	p = l.pHead;
	
		while ((p != NULL) && (p->infor != a))
		{

			p = p->pNext;
			i++;

		}
		if (p == NULL)
		{
			cout << "\nKo co x trong DS";
			return NULL;
		}
		cout << "\nVi tri x trong ds la:" << i;
		
	
}
int timvt_X_last(LIST l, Data x)
{
	int vt,i=0 ;
	NODE* p;
	p = l.pHead;
	vt = 0;
	while (p != NULL)
	{
		
		if (p->infor == x)
		{
			vt = i;
		}
		i++;
		p = p->pNext;
	}
	return vt+1 ;
}

void chenXvaodauDS(LIST &l, Data x) {
	NODE* newp;
	
	newp = getnode(x);
	l.pHead;
	if (l.pHead == NULL)
	{
		l.pHead =newp ;
		l.pTail = l.pHead;
	}
	else
	{
		 newp->pNext=l.pHead;
		  l.pHead = newp;
	}


}
void chenXvaocuoiDS(LIST& l, Data x) {

	NODE* newp;
	
	newp = getnode(x);
	
	if (l.pHead == NULL)
	{
		l.pHead = newp;
		l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = newp;
		l.pTail = newp;
	}


}

void ADDfirst(LIST& l, NODE* newp)
{
	if (l.pHead == NULL)
	{
		l.pHead = newp;
		l.pTail = newp;
	}
	else
		newp->pNext = l.pHead;
		l.pHead = newp;

}

void AddAfter(LIST &l, NODE* q, Data x )
{
	NODE* newp;
	newp = getnode(x);
	if (q != NULL)
	{
		newp->pNext = q->pNext;
		q->pNext = newp;
	}
	else if (q = l.pTail)
	{
		newp = l.pTail;

	}

	else
		ADDfirst(l, newp);

}

NODE*  tim_Nut_trongDS(LIST& l, Data x)
{
	
	NODE*p,*q = NULL;
	p = l.pHead;
	while (p != NULL)
	{
		if (p->infor == x)
		{
			q = p;

		}
		p=p->pNext;
	}
	return q;
}

void chenXvaoY(LIST& l, Data x, Data y)
{
	NODE* q;

	q = tim_Nut_trongDS(l, x);
	 AddAfter(l, q, x);

}

int huydauDS(LIST& l)
{
	Data x;
	NODE* p; 
	if (l.pHead != NULL)
	{
		p = l.pHead;
		x = p->infor;

		l.pHead = l.pHead->pNext;
		
		
		if (l.pHead == NULL)
		{
			l.pTail = NULL;
		}

	}

	return x;
}
void huycuoiDS(LIST& l)
{
	NODE* p;
	NODE* q;
	p = l.pHead;
	q = NULL;
	while (p != l.pTail)
	{
		
		q = p;
 		p=p->pNext;
	}
	l.pTail = p;
	l.pTail = q;
	delete p;
	
	if (l.pTail == NULL)
	
		l.pHead == NULL;
	
	else
		 l.pTail->pNext = NULL;
}



int huy_x_DS(LIST& l,Data x)
{
	NODE* p, * q = NULL;
	p = l.pHead;
	while (p != NULL)
	{
		if (p->infor == x)
			break;
		q = p;
		p = p->pNext;
	}
	if (p == NULL)
		return 0;
	if (q != NULL)
	{
		if(p==l.pTail)
			l.pTail = q;

		q->pNext = p->pNext;
		delete p;
	}
	else
	{
		l.pHead = p->pNext;

		if (l.pHead == NULL)
		{
			l.pTail == NULL;
		}
	}
	

}
void xoa_DS(LIST& l)
{
	NODE* p;
	
	while (l.pHead != NULL)
	{
		p = l.pHead;
		l.pHead = p->pNext;
		delete p;

	}
	l.pTail = NULL;
}

void hoanvi(Data &p, Data &q)
{

	int t = p;
	p = q;
	q = t;

}

void sapxeptang_chontructiep_dulieu(LIST& l)
{
	NODE* p, *q;
	NODE* min;
	p = l.pHead;
	while (p != l.pTail)
	{
		min = p;
		
		q = p->pNext;
		while (q != NULL)
		{
			if (q->infor < min->infor)
			
				min = q;

				q = q->pNext;
			
		}
		hoanvi(min->infor, p->infor);
		p = p->pNext;
	}
}
void listselectionsort2(LIST& l)
{
	LIST  lres; // DS moi

	NODE* min;
	NODE* p, * q, * minprev;

	createList(lres);//khoi tao ds moi

	while (l.pHead != NULL)
	{
		p = l.pHead;
		q = p->pNext;
		min = p;
		minprev = NULL;
		while (q != NULL) {
			if (q->infor < min->infor)
			{
				min = q;
				minprev = p;
			}
				p = q;  
				q = q->pNext;

		}
			 if (minprev != NULL)
				minprev->pNext = min->pNext;
			else
				l.pHead = min->pNext;
				min->pNext = NULL;
				AddTail(lres, min);
			
	}
	l = lres;
}

