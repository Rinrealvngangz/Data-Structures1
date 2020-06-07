#pragma once

Graph OpenGraph(char filename[])
{
	ifstream is(filename);

	if (is.is_open()) {
		int n = 0; //so dinh
		int m = 0;//so cach
		bool d = true;//loai do thi true co huong ,false ko huong
		
		LableType lab;
		is >> n;
		is >> m;
		is >> d;
		int t;
		Graph g = InitGraph(d);
		g.NumEdges = m;
		//khoi tao nhan  dinh 
		for (size_t i = 0; i < n; i++)
		{
			is >> lab;

			AddVertex(g, lab);
		}

		for (size_t i = 0; i < n; i++)

			for (size_t j = 0; j < n; j++)
			{
				is >> t;
				if (t != 0)
				{
					g.Cost[i][j] = t;

				}
			}
		is.close();
		cout << "Mo file thanh cong";
		return g;
	}

}

void DisplayMatrix(Graph g)
{
	cout << endl;
	
	for (size_t i = 0; i < g.NumVertices; i++)
		cout << '\t' << g.Vertices[i].Lable;
	cout << endl;
	for (size_t i = 0; i < g.NumVertices; i++)
	{
		cout << g.Vertices[i].Lable << '\t';
		for (size_t j = 0; j < g.NumVertices; j++)
		{
			cout << g.Cost[i][j] << '\t';
			
		}
		cout << endl;
	}
	cout << endl;
}

void themMotDinh(Graph& g, LableType lab)
{
	Vertex v = CreateVertex(lab);

	g.Vertices[g.NumVertices] = v;
	g.NumVertices++;

	g.Cost[g.NumVertices - 1][g.NumVertices-1] = 0;

	for (size_t i = 0; i < g.NumVertices-1; i++)
	{
		g.Cost[i][g.NumVertices - 1] = INF;
		g.Cost[g.NumVertices - 1][i] = INF;
	}
}

int timDinh(Graph g, LableType label)
{
	for (size_t i = 0; i < g.NumVertices; i++)
	{
		if (g.Vertices[i].Lable == label)
			return i;
	}
		return -1;
}

void hienThiThongTinDinhTaiVitri(Graph g, int pos)
{
	LableType v = g.Vertices[pos].Lable;
	cout << "Cac dinh ke voi  : " << v <<" La: ";
	 
	for (size_t i = 0; i < g.NumVertices; i++)
	{

		if(g.Cost[pos][i] != 0)
			
		cout << g.Vertices[i].Lable << '\t';
	}
}

void kiemTraHaiDinhkeNhau(Graph g, LableType u, LableType v)
{
	int p1, p2;
	
		p1 = timDinh(g, u);
		p2 = timDinh(g, v);
		if (IsConnected(g, p1, p2))
		{
			cout << "Hai dinh " << u << " va " << v << " ke  nhau.";
		}
		else
			cout << "Hai dinh " << u << " va " << v << " khong ke nhau.";

}

void ThemCanhCoTrongSo(Graph g , LableType u, LableType v)
{
	int p1, p2;
	int w;
	p1 = timDinh(g, u);
	p2 = timDinh(g, v);
	cout << "\nNhap trong so w:";
	cin >> w;

	AddEdge(g, p1, p2, w, g.Directed);
	cout << "\nDo thi sau khi them canh:";
	DisplayMatrix(g);
}

void saveFile(Graph g, char file[])
{
	ofstream os(file);
	if (os.is_open())
	{
		os << g.NumVertices <<"\n";
		os << g.NumEdges << "\n";
		os << g.Directed << "\n";

		for (size_t i = 0; i < g.NumVertices; i++)
			os << g.Vertices[i].Lable << "\n";
		for (size_t i = 0; i < g.NumVertices; i++)
		{
			for (size_t j = 0; j < g.NumVertices; j++)
			{
				os << g.Cost[i][j] << '\t';

			}
			os << endl;
		}
		os.close();
	}
}

void BFS_Loop(Graph g, int start)
{
	ResetFlags(g);
	g.Vertices[start].Visited = YES;
	queue<int> q;
	q.push(start);
	int curr, dinhLienKe;

	while (!q.empty())
	{
	  curr =  q.front();
		 q.pop();
		 DisplayVertex(g, curr);
		 while (true)
		 {
			 dinhLienKe = FindFirstAdjacentVertex(g, curr);

			 if (dinhLienKe == NULLDATA)
				 break;
			 else
			 {
				 g.Vertices[dinhLienKe].Visited = YES;
				 q.push(dinhLienKe);
			 }
		 }		
	}

}

void DFS(Graph g, int start)
{
	ResetFlags(g);
	
	DisplayVertex(g, start);
	g.Vertices[start].Visited = YES;
	//int count = 1;
	stack<int>s;
	s.push(start);

	int curr, DinhLienKe;

	while (!s.empty())
	{
		curr = s.top();
	 DinhLienKe =FindFirstAdjacentVertex(g, curr);
	 if (DinhLienKe == NULLDATA)
	 {
		 s.pop();
		 if(s.empty() ==true)
		 break;
	 }
		
	 else
	 {
		 DisplayVertex(g, DinhLienKe);
		 g.Vertices[DinhLienKe].Visited = YES;
		// count++;
		 s.push(DinhLienKe);
	 }
	}
	//return count;
}

void DFS_Dequy(Graph& g, int start)
{
	
	g.Vertices[start].Visited = YES;
	DisplayVertex(g, start);

	while (true)
	{
		int adj = FindFirstAdjacentVertex(g, start);
		if (adj == NULLDATA)
			break;
		DFS_Dequy(g, adj);
	}

}

/*void KT_LienThong(Graph g)
{
	int count = 0;
	int flag =0;

	for (size_t i = 0; i < g.NumVertices; i++)
	{
		if (g.Vertices[i].Visited == NO)
		{
			count++;
			cout << "\nThanh phan lien thong thu " << count << ": \t";
			if (DFS(g, i) == g.NumVertices)
				flag = 1;
		}
	}
	cout << "\nCon lai " << count << " lan duyet.";
	if (flag)
		cout << "\nLien thong!";
	else cout << "\nKhong lien thong!";
}*/