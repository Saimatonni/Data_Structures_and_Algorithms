#include<bits/stdc++.h>
using namespace std;
int const N = 105;
int const inf = 199999;
int path[N];
vector<int> dist(N, inf), vis(N, 0);
vector<vector<int>> g(N);

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

	queue<int> q;

	q.push(0);
	dist[0] = 0;

	path[0] = -1;

	while(!q.empty())
	{
		int u = q.front();
		q.pop();

		vis[u]  = 1;

		for(auto v : g[u]) if(!vis[v]) {
			vis[v] = 1;
			if(dist[v] > dist[u] + 1){
				dist[v] = dist[u] + 1;
				path[v] = u;
			}
			else if(dist[v] == dist[u] + 1 && path[v] > u){
				path[v] = u;
			}
			q.push(v);
		}
	}

	for(int i = 0; i < n; i++)
	{
		cout<<i<<": ";
		if(dist[i] == inf){
			cout<<"Not Reachable";
		}
		else{
			int u = i;
			vector<int> ans;
			ans.push_back(u);
			while(path[u] != -1) {
				ans.push_back(path[u]);
				u = path[u];
			}
			reverse(ans.begin(), ans.end());
			for(int i = 0; i < ans.size(); i++){
				cout<<ans[i];
				if(i != ans.size() - 1) cout<<" ";
			}
		}
		cout<<endl;
	}

}
