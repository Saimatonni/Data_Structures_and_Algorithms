#include<bits/stdc++.h>
using namespace std;
class graph{
    int v;
    list<int>*adj;
 public:
    graph(int v);
    void addedge(int x, int y);
    void bfs(int s);
};

graph::graph(int v){
    this->v=v;
    adj=new list<int>[v];
}

void graph::addedge(int x,int y){
    adj[x].push_back(y);
}

void graph::bfs(int s){
    bool*visit = new bool[v];
    for(int i=0;i<v;i++){
        visit[i]=false;
    }
    list<int>q;
    visit[s]=true;
    q.push_back(s);
    list<int>::iterator i;
    while(!q.empty()){
        s=q.front();
        cout<<s<<" ";
        q.pop_front();
        for(i=adj[s].begin();i!=adj[s].end();i++){
            if(!visit[*i]){
                visit[*i]=true;
                q.push_back(*i);
            }
        }
    }
}

int main(){
    graph g(4);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,2);
    g.addedge(2,0);
    g.addedge(2,3);
    g.addedge(3,3);
    g.bfs(2);
    return 0;
}