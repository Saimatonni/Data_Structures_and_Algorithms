//30

#include<bits/stdc++.h>
using namespace std;
int const N = 103;

#define vi vector<int>
int ej[N][N];
vi start(N,  0), endt(N, 0), par(N), vis(N, 0);
vector<vi> g(N);
int n, m;
int times;

void dfs(int u)
{
	start[u] = times;
	times += 1;
	vis[u] = 1;

	for(auto v : g[u]){
		if(!vis[v]){
			ej[u][v] = 1;
			dfs(v);
		}
	}
	endt[u] = times;
	times += 1;
}

int main()
{
	cin>>n>>m;

	for(int i = 0; i < m; i++){
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
	}
	for(int i = 0; i < n; i++)
		sort(g[i].begin(), g[i].end());
	int no = 1;
	times = 0;
	for(int i = 0; i < n; i++){
		if(vis[i] == 0) {
			par[i] = -1;
			dfs(i);
		}
	}
	for(int u = 0; u < n; u++){

		for(auto v : g[u])
		{
			char ch;
			if(u == v) ch = 'B';
			else if(start[u] < start[v] && endt[u] > endt[v] && ej[u][v])
				ch = 'T';
			else if(start[u] > start[v] && endt[u] < endt[v])
				ch = 'B';
			else if(start[u] < start[v] && endt[u] > endt[v])
				ch = 'F';
			else ch = 'C';

			cout<<u<<" "<<v<<" "<<"("<<ch<<")"<<endl;
		}
	}
}
