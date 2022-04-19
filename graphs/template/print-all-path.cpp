#include<bits/stdc++.h>
using namespace std;
void printpath(vector<int>& path){
    int s=path.size();
    for(int i=0;i<s;i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
}
int checkvisition(int x,vector<int>& path){
    int s=path.size();
    for(int i=0;i<s;i++){
        if(path[i]==x){
            return 0;
        }
    }
    return 1;
}

void paths(vector<vector<int>>&g,int src,int dst,int v){
    queue<vector<int>> q;
    vector<int>path;
    path.push_back(src);
    q.push(path);
    while(!q.empty()){
        path=q.front();
        q.pop();
        int last=path[path.size()-1];
        if(last==dst){
            printpath(path);
        }
        for(int i=0;i<g[last].size();i++){
            if(checkvisition(g[last][i],path)){
               vector<int>newp(path);
               newp.push_back(g[last][i]);
               q.push(newp);
            }
        }
    }
}
int main(){
    vector<vector<int>>g;
    int v=4;
    g.resize(4);
    g[0].push_back(3);
    g[0].push_back(1);
    g[0].push_back(2);
    g[1].push_back(3);
    g[2].push_back(0);
    g[2].push_back(1);
    int src=2,dst=3;
    paths(g,src,dst,v);
    return 0;
}