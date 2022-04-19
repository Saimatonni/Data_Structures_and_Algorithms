#include <bits/stdc++.h>
using namespace std;
class graph
{
public:
    map<int, bool> visit;
    map<int, list<int>> adj;
    void addedge(int x, int y);
    void dfs(int v);
};
void graph::addedge(int x, int y)
{
    adj[x].push_back(y);
}

void graph::dfs(int v)
{
    visit[v] = true;
    cout << v << " ";
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); i++)
    {
        if (!visit[*i])
        {
            dfs(*i);
        }
    }
}
int main(){
    graph g;
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,2);
    g.addedge(2,0);
    g.addedge(2,3);
    g.addedge(3,3);
    g.dfs(2);
    return 0;
}