
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
int const N = 1e2 + 10;
vi col(N, -1);
vector<vi> g(N);

int dfs(int u, int pr)
{

	for(auto v : g[u]) if(v != pr){
		if(col[v] == -1){
			col[v] = 1 - col[u];
			if(dfs(v, u))
				return 1;
		}
		else if(col[v] == col[u])
			return 1;
	}
	col[u] = 2;
	return false;
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

	int ans = 1;
	for(int i = 0; i < n; i++) if(col[i] == -1){
		col[i] = 1;
		if(dfs(i, -1)){
			ans = 0;
		}
	}

	if(ans) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

	///for(int i = 0; i < n; i++) cout<<col[i]<<" ";
}
