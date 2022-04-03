
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int const N = 1e2 + 10;
int const inf = 696969;
string g[N];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
bool valid(int x, int y)
{
	return (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == '.');
}

int main()
{
	cin>>n>>m;
	for(int i = 0; i < n; i++) cin>>g[i];

	vector<vector<int>> dist(n, vector<int>(m, inf));
	queue<pii> q;
	
	q.push(pii(0, 0));
	dist[0][0] = 0;

	while(!q.empty())
	{
		pii u = q.front();
		q.pop();

		for(int i = 0; i < 4; i++){
			int x = u.first + dx[i];
			int y = u.second + dy[i];

			if(valid(x, y) && dist[x][y] > dist[u.first][u.second] + 1){
				dist[x][y] = dist[u.first][u.second] + 1;
				q.push(pii(x, y));
			}
		}
	}
	if(dist[n-1][m-1] == inf) dist[n-1][m-1] = -1;
	cout<<dist[n-1][m-1]<<endl;
}
