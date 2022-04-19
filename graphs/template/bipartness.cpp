#include<bits/stdc++.h>
using namespace std;
#define V 4
bool bipartness(int g[][V],int src){
    int color[V];
    for(int i=0;i<V;++i){
        color[i]=-1;
    }
    color[src]=1;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(g[u][u]==1){
            return false;
        }
        for(int v=0;v<V;v++){
            if(g[u][v]&&color[v]==-1){
                color[v]=1-color[u];
                q.push(v);
            }
            else if(g[u][v]&&color[v]==color[u]){
                return false;
            }
        }
    }
    return true;
}
int main()
{
	int G[][V] = {{0, 1, 0, 1},
		{1, 0, 1, 0},
		{0, 1, 0, 1},
		{1, 0, 1, 0}
	};

	bipartness(G, 0) ? cout << "Yes" : cout << "No";
	return 0;
}
