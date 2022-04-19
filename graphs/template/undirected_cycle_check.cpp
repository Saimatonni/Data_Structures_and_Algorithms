#include <bits/stdc++.h>
using namespace std;
class graph
{
    int v;
    list<int> *adj;
    bool iscyclic(int v, bool visit[], int p);

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
    adj[y].push_back(x);
}

bool graph::iscyclic(int v, bool visit[], int p)
{
    visit[v] = true;

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if (!visit[*i])
        {
            if(iscyclic(*i,visit,v)){
               return true;
            }
           
        }
        else if (*i != p)
        {
            return true;
        }
    }

    // resstack[v]=false;
    return false;
}
bool graph::cycle()
{
    bool *visit = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visit[i] = false;
    }
    for (int i = 0; i < v; i++)
    {
        if (!visit[i])
        {
            if(iscyclic(i,visit,-1)){
               return true;
            }
           
        }
    }
    return false;
}
int main()
{
    graph g1(5);
    g1.addedge(1, 0);
    g1.addedge(0, 2);
    g1.addedge(2, 1);
    g1.addedge(0, 3);
    g1.addedge(3, 4);
    if(g1.cycle())
        cout << "Graph contains cycle"<<endl;
    else
        cout << "Graph doesn't contain cycle"<<endl;
 
    graph g2(3);
    g2.addedge(0, 1);
    g2.addedge(1, 2);
    if(g2.cycle())
        cout << "Graph contains cycle"<<endl;
    else
        cout << "Graph doesn't contain cycle"<<endl;
    return 0;
}