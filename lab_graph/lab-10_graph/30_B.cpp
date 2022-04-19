//30

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
int const N = 1e4 + 10;
vi col(N, 0);
vector<vi> g(N);

void dfs(int u)
{

	col[u] = 1;
	for(auto v : g[u])
		if(!col[v])
			dfs(v);
}
int main()
{
	int n, m;
	cin>>n>>m;
	for(int i = 0; i < m; i++){
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int ans = -1;
	for(int i = 1; i <= n; i++) if(!col[i]){
		ans++;
		dfs(i);
	}

	cout<<ans<<endl;
}

