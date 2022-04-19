#include<bits/stdc++.h>
using namespace std;
class graph{
    int v;
    list<int>*adj;
 public:
    graph(int v);
    void addedge(int x, int y);
    bool reachable(int s,int d);
};

graph::graph(int v){
    this->v=v;
    adj=new list<int>[v];
}

void graph::addedge(int x,int y){
    adj[x].push_back(y);
}

bool graph::reachable(int s,int d){
    if (s == d)
      return true;

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
        //cout<<s<<" ";
        q.pop_front();
        for(i=adj[s].begin();i!=adj[s].end();i++){
            if(*i==d){
                return true;
            }
            if(!visit[*i]){
                visit[*i]=true;
                q.push_back(*i);
            }
        }
    }
    return false;
}
int main(){
    graph g(4);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,2);
    g.addedge(2,0);
    g.addedge(2,3);
    g.addedge(3,3);
    int u=3,v=1;
    if(g.reachable(u,v)){
        cout<<" yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
    return 0;
}
