#include<bits/stdc++.h>
using namespace std;

void addedge(vector<int>adj[],int x,int y){
    adj[x].push_back(y);
    adj[y].push_back(x);
}

bool bfs(vector<int>adj[],int src,int dest,int v,int prev[],int dist[]){
    list<int>q;
    bool visit[v];
    for(int i=0;i<v;i++){
        visit[i]=false;
        dist[i]=INT_MAX;
        prev[i]=-1;
    }
    visit[src]=true;
    dist[src]=0;
    q.push_back(src);
    while(!q.empty()){
        int u=q.front();
        q.pop_front();
        for(int i=0;i<adj[u].size();i++){
            if(visit[adj[u][i]]==false){
                visit[adj[u][i]]=true;
                dist[adj[u][i]]=dist[u]+1;
                prev[adj[u][i]]=u;
                q.push_back(adj[u][i]);
                if(adj[u][i]==dest){
                    return true;
                }
            }
        }
    }
    return false;
}

void sortestpath(vector<int>adj[],int src,int dest,int v){
    int prev[v],dist[v];
    if(bfs(adj,src,dest,v,prev,dist)==false){
        cout<<"not connrcted"<<endl;
        return;
    }
    vector<int>path;
    int store=dest;
    path.push_back(store);
    while(prev[store]!=-1){
        path.push_back(prev[store]);
        store=prev[store];
    }
    cout<<"sortest path length  "<<dist[dest]<<endl;
    cout<<"path :"<<endl;
    for(int i=path.size()-1;i>=0;i--){
        cout<<path[i]<<" ";
    }
}

int main(){
    int v=8;
    vector<int> adj[v];
    addedge(adj, 0, 1);
    addedge(adj, 0, 3);
    addedge(adj, 1, 2);
    addedge(adj, 3, 4);
    addedge(adj, 3, 7);
    addedge(adj, 4, 5);
    addedge(adj, 4, 6);
    addedge(adj, 4, 7);
    addedge(adj, 5, 6);
    addedge(adj, 6, 7);
    int source = 0, dest = 7;
    sortestpath(adj, source, dest, v);
    return 0;
}