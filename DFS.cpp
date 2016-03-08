#include<bits/stdc++.h>
using namespace std;
#define MAX 100

//Nhap Input Tu File
void Init(int G[][MAX], int &n )
{
	fstream doc("test.txt", ios::in);
	if(!doc) 
	{
		cout<<"Khong Co File Input";
		
	}
	else 
	{
		doc>>n;
		for(int i = 0 ; i < n ; i ++)
			for(int j = 0 ; j < n ; j ++)
			{
				doc>>G[i][j];				
			}					
	}
}
//Cai Dat DFS Bang De Qui
void DFS(int G[][MAX], int n, int v, bool chuaxet[])
{
	cout<<v;
	chuaxet[v] = false;
	for(int u = 1 ; u <= n ; u++)
	{
		if(G[v][u] == 1 && chuaxet[u])
		{
			DFS(G, n, u, chuaxet);
		}
	}
}

int main()
{
	
	int	G[MAX][MAX], n;
	bool chuaxet[MAX];
	Init(G,n);
	for(int i = 1 ; i <= n ; i ++)	
	{
		chuaxet[i] = true;
	}
	cout<<endl<<endl;
	for(int i = 1 ; i <= n ; i ++)
	{
		if(chuaxet[i])
		{
			DFS(G, n, i, chuaxet);
		}
	}

	return 0;
}


