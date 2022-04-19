#include<bits/stdc++.h>
using namespace std;
vector<bool>v;
vector<vector<int>> gph;
void edge(int x,int y){
    gph[x].push_back(y);
    // for undirected graph gph[y].push_back(x)
}

void bfs(int val){
    queue<int> q;
    q.push(val);
    v[val]=true;
    while(!q.empty()){
        int fr=q.front();
        q.pop();
        cout<<fr<<" ";
        for(auto i=gph[fr].begin();i!=gph[fr].end();i++){
             if(!v[*i]){
                 q.push(*i);
                 v[*i]=true;
             }
        }
    }
}
int main(){
    int n,e;
    cin>>n>>e;
    v.assign(n,false);
    gph.assign(n,vector<int>());
    int x,y;
    for(int i=0;i<e;i++){
        cin>>x>>y;
        edge(x,y);
    }
    for(int i=0;i<n;i++){
        if(!v[i]){
            bfs(i);
        }
    }
    return 0;
}