#include <bits/stdc++.h>
using namespace std;
class graph
{
    int v;
    list<int> *adj;
    bool iscyclic(int v, bool visit[], bool *rs);

public:
    graph(int v);
    void addedge(int x, int y);
    bool cycle();
};

graph::graph(int v)
{
    this->v = v;
    adj = new list<int>[v];
}

void graph::addedge(int x, int y)
{
    adj[x].push_back(y);
}

bool graph::iscyclic(int v, bool visit[], bool *resstack)
{
    if (visit[v] == false)
    {
        visit[v] = true;
        resstack[v] = true;
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if (!visit[*i] && iscyclic(*i,visit,resstack))
            {
                return true;
            }
            else if(resstack[*i]){
                return true;
            }
        }
    }
    resstack[v]=false;
    return false;
}
bool graph::cycle(){
    bool *visit =new bool[v];
    bool *resstack = new bool[v];
    for(int i=0;i<v;i++){
        visit[i]=false;
        resstack[i]=false;
    }
    for(int i=0;i<v;i++){
        if (!visit[i] && iscyclic(i,visit,resstack))
            {
                return true;
            }
    }
    return false;
}
int main(){
    graph g(4);
    g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(1, 2);
    g.addedge(2, 0);
    g.addedge(2, 3);
    g.addedge(3, 3);
 
    if(g.cycle())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}