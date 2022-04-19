#include<bits/stdc++.h>
using namespace std;
class graph{
    int v;
    list<int>* adj;
 public:
    graph(int v);
    void addedge(int x, int y,int w);
    int findsortestpath(int s,int d);
    int printspath(int p[],int s,int d);
};

graph::graph(int v){
    this->v=v;
    adj=new list<int>[2*v];
}
void graph::addedge(int x,int y,int w){
    if(w==2){
        adj[x].push_back(x+v);
        adj[x+v].push_back(y);
    }
    else{
       adj[x].push_back(y);
    }
}

int graph::printspath(int p[],int s,int d){
    static int l=0;
    if(p[s]==-1){
        cout<<"sortest path is : "<<s<<" ";
        return l;
    }
    printspath(p,p[s],d);
    l++;
    if(s<v){
        cout<<s<<" ";
    }
    return l;
}

int graph::findsortestpath(int s,int d){
    bool *visit = new bool[2*v];
    int *p= new int[2*v];
    for(int i=0;i<2*v;i++){
        visit[i]=false;
        p[i]=-1;
    }
    list<int>q;
    visit[s]=true;
    q.push_back(s);
    list<int>::iterator i;
    while(!q.empty()){
        int src=q.front();
        if(src==d){
            return printspath(p,src,d);
        }
        //cout<<s<<" ";
        q.pop_front();
        for(i=adj[src].begin();i!=adj[src].end();i++){
            if(!visit[*i]){
                visit[*i]=true;
                q.push_back(*i);
                p[*i]=src;
            }
        }
    }
    return 0;
}
int main()
{
    // Create a graph given in the above diagram
    int V = 4;
    graph g(V);
    g.addedge(0, 1, 2);
    g.addedge(0, 2, 2);
    g.addedge(1, 2, 1);
    g.addedge(1, 3, 1);
    g.addedge(2, 0, 1);
    g.addedge(2, 3, 2);
    g.addedge(3, 3, 2);
  
    int src = 0, dest = 3;
    cout<< g.findsortestpath(src, dest);
  
    return 0;
}