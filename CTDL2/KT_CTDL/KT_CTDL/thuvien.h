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

void Prim(Graph g, Path tree[MAX])
{
	for (size_t i = 1; i < g.NumVertices; i++)		//Khởi tạo cây ban đầu
	{
		tree[i].Length = g.Cost[0][i];
		tree[i].Parent = 0;
	}
	CostType min;		//Lưu cạnh có trọng số nhỏ nhất
	int minVertex;		//Lưu đỉnh cuối của cạnh đó
	for (size_t i = 1; i < g.NumVertices; i++)		//Tìm n-1 cạnh cho cây
	{
	
		min = INF;
		minVertex = 1;
		for (size_t j = 1; j < g.NumVertices; j++)	//Tìm cạnh min
			if (g.Vertices[j].Visited == NO && tree[j].Length < min)
			{
				min = tree[j].Length;
				minVertex = j;
			}
		g.Vertices[minVertex].Visited = YES;
		for (size_t j = 0; j < g.NumVertices; j++)	//Thêm vào cây
			if (g.Vertices[j].Visited == NO && g.Cost[minVertex][j] < tree[j].Length)
			{
				tree[j].Length = g.Cost[minVertex][j];
				tree[j].Parent = minVertex;
			}
	}
}
void PrintPrimMST(Graph g, Path tree[MAX])
{
	cout << endl << "Cay bao trum gom cac canh sau:";
	CostType sum = 0;
	cout << endl << '|' << setw(10) << "Dinh Dau" << '|' << setw(10) << "Dinh Cuoi" << '|' << setw(10) << "Trong so" << '|';
	for (size_t i = 1; i < g.NumVertices; i++)
	{
		sum += tree[i].Length;
		cout << endl << '|' << setw(10) << g.Vertices[tree[i].Parent].Lable << '|' << setw(10) << g.Vertices[i].Lable << '|' << setw(10) << tree[i].Length << '|';
	}
	cout << "\nCay bao trum ngan nhat co chieu dai: " << sum;
}


//==========================Kruskal===============================

//Lấy ra danh sách cạnh
/*int AdjMatrix2EdgeList(Graph g, Edge edgeList[UPPER])
{
	int count = 0;
	for (size_t i = 1; i < g.numVertices; i++)
		for (size_t j = 0; j < i; j++)
			if (g.cost[i][j] != 0 && g.cost[i][j] != 1000)
			{
				Edge v;
				v.source = i;
				v.target = j;
				v.weight = g.cost[i][j];
				v.marked = NO;
				edgeList[count] = v;
				count++;
			}
	return count;
}

//Sắp xếp danh sách cạnh
void QuickSortEdges(Edge edgeList[MAX], int d, int c)
{
	int i = d, j = c;
	CostType mid = edgeList[(d + c) / 2].weight;
	while (i <= j)
	{
		while (edgeList[i].weight < mid)i++;
		while (edgeList[j].weight > mid)j--;
		if (i <= j)
		{
			swap(edgeList[i], edgeList[j]);
			i++;
			j--;
		}
	}
	if (i < c)QuickSortEdges(edgeList, i, c);
	if (d < j)QuickSortEdges(edgeList, d, j);
}

//Tìm nút gốc của cây chứa đỉnh x
int Find(int leader[MAX], int x)
{
	while (x != leader[x])x = leader[x];
	return x;
}

//Hợp 2 cây bằng cách nối thêm cạnh e
bool Union(int leader[MAX], Edge e)
{
	int x = Find(leader, e.source);
	int y = Find(leader, e.target);
	if (x == y)			//Nếu trùng gốc
		return false;
	else if (x < y)		//Nhập cây y vào cây x
		leader[y] = x;
	else leader[x] = y;
	return true;
}

void Kruskal(Graph g, Edge tree[UPPER])
{
	int ne = AdjMatrix2EdgeList(g, tree);
	QuickSortEdges(tree, 0, ne - 1);
	int leader[MAX];
	for (size_t i = 0; i < g.numVertices + 1; i++)	//Khởi tạo đỉnh gốc của cây con
		leader[i] = i;
	int count = 0;
	for (size_t i = 0; i < ne; i++)
	{
		if (Union(leader, tree[i]))			//Nếu ghép được vào cây bao trùm
		{
			tree[i].marked = YES;
			count++;
			if (count == g.numVertices - 1)	//Nếu đủ n-1 cạnh
				break;
		}
	}
}

void PrintKruskalMST(Graph g, Edge tree[UPPER])
{
	cout << endl << "Cay bao trum gom cac canh sau: ";
	CostType sum = 0;
	cout << endl << '|' << setw(10) << "Dinh Dau" << '|' << setw(10) << "Dinh Cuoi" << '|' << setw(10) << "Trong so" << '|';
	for (size_t i = 0; i < g.numVertices; i++)
	{
		if (tree[i].marked == YES)
		{
			cout << endl << '|' << setw(10) << g.Vertices[tree[i].source].label << '|' << setw(10) << g.Vertices[tree[i].target].label << '|' << setw(10) << tree[i].weight << '|';
			sum += tree[i].weight;
		}
	}
	cout << endl << "Tong chieu dai cay bao trum la " << sum;
}

//===============================Dijkstra===============================

//Thuật toán Dijkstra
void Dijkstra(Graph g, int source, Path road[MAX])
{
	CostType min;
	int counter, minVertex, curr;
	for (size_t i = 0; i < g.numVertices; i++)
	{
		road[i].length = g.cost[source][i];
		road[i].parent = source;
	}
	g.Vertices[source].visited = YES;
	counter = 1;
	curr = source;
	while (counter < g.numVertices - 1)
	{
		min = INF;
		minVertex = curr;
		for (size_t i = 0; i < g.numVertices; i++)
		{
			if (g.Vertices[i].visited == NO)
			{
				if (road[i].length > road[curr].length + g.cost[curr][i])
				{
					road[i].length = road[curr].length + g.cost[curr][i];
					road[i].parent = curr;
				}
				if (min > road[i].length)
				{
					min = road[i].length;
					minVertex = i;
				}
			}
		}
		curr = minVertex;
		g.Vertices[curr].visited = YES;
		counter++;
	}
}

//In đoạn đường từ đỉnh đó đến đỉnh target
void PrintPath_Dijkstra(Graph g, Path road[MAX], int target)
{
	if (road[target].parent != target)
		PrintPath_Dijkstra(g, road, road[target].parent);
	cout << '\t' << g.Vertices[target].label;
}

//In các đoạn đường đến các đỉnh
void PrintAllPath_Dijkstra(Graph g, int start)
{
	Path road[MAX];
	Dijkstra(g, start, road);
	for (size_t i = 0; i < g.numVertices; i++)
	{
		if (road[i].length == INF)
			cout << "\nKhong co duong di tu " << g.Vertices[start].label << " den " << g.Vertices[i].label;
		else if (i != start)
		{
			cout << "\nDoan duong tu " << g.Vertices[start].label << " den " << g.Vertices[i].label << " la : ";
			PrintPath_Dijkstra(g, road, i);
			cout << "\t(Tong do dai: " << road[i].length << ')';
		}
	}
}

//===============================Floyd===============================

void Floyd(Graph g, Path route[MAX][MAX])
{
	for (size_t i = 0; i < g.numVertices; i++)
		for (size_t j = 0; j < g.numVertices; j++)
		{
			route[i][j].length = g.cost[i][j];
			route[i][j].parent = i;
		}
	for (size_t k = 0; k < g.numVertices; k++)
		for (size_t i = 0; i < g.numVertices; i++)
			for (size_t j = 0; j < g.numVertices; j++)
				if (route[i][j].length > route[i][k].length + route[k][j].length)
				{
					route[i][j].length = route[i][k].length + route[k][j].length;
					route[i][j].parent = route[k][j].parent;
				}
}

void PrintPath_Floyd(Graph g, Path route[MAX][MAX], int source, int target)
{
	if (route[source][target].parent != target)
	{
		PrintPath_Floyd(g, route, source, route[source][target].parent);
		cout << '\t' << g.Vertices[target].label;
	}
}

void PrintAllPath_Floyd(Graph g)
{
	Path route[MAX][MAX];
	Floyd(g, route);
	for (size_t i = 0; i < g.numVertices; i++, cout << endl)
		for (size_t j = 0; j < g.numVertices; j++)
		{
			if (route[i][j].length == INF)
				cout << "\nKhong co duong di tu dinh " << g.Vertices[i].label << " den dinh " << g.Vertices[j].label;
			else if (i != j)
			{
				cout << "\nDoan duong tu dinh " << g.Vertices[i].label << " den dinh " << g.Vertices[j].label << " la: ";
				PrintPath_Floyd(g, route, i, j);
			}
		}
}*/