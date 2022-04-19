//30
//30
//30
//30
//30
//30
//30
//30
#include <bits/stdc++.h>
#include<cstring>
using namespace std;
class DisjSet {
    int *rank, *parent, n;
  
public:
    DisjSet(int n)
    {
        rank = new int[n];
        parent = new int[n];
        this->n = n;
        makeSet();
    }
  
    // Creates n single item sets
    void makeSet()
    {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
  
    // Finds set of given item x
    int find(int x)
    {
        
        if (parent[x] != x) {
  
            parent[x] = find(parent[x]);
  
            
        }
  
        return parent[x];
    }
    struct Edge
{
    int src, dest;
};
 
// a structure to represent a graph
struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    int V, E;
 
    // graph is represented as an array of edges
    struct Edge* edge;
};
 
// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph =
           (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;
 
    graph->edge =
        (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
 
    return graph;
}
 int find(int parent[], int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}
 
// A utility function to do union of two subsets
void Union(int parent[], int x, int y)
{
    parent[x] = y;
}
 
  
    int isCycle( struct Graph* graph )
{
    // Allocate memory for creating V subsets
    int *parent = (int*) malloc( graph->V * sizeof(int) );
 
    // Initialize all subsets as single element sets
    memset(parent, -1, sizeof(int) * graph->V);
 
    // Iterate through all edges of graph, find subset of both
    // vertices of every edge, if both subsets are same, then
    // there is cycle in graph.
    for(int i = 0; i < graph->E; ++i)
    {
        int x = find(parent, graph->edge[i].src);
        int y = find(parent, graph->edge[i].dest);
 
        if (x == y)
            return 1;
 
        Union(parent, x, y);
    }
    return 0;
}
    void Union(int x, int y)
    {
        // Find current sets of x and y
        int xset = find(x);
        int yset = find(y);
  
        // If they are already in same set
        if (xset == yset)
            return;
  
        if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        }
        else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        }
  
        else {
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;
        }
    }
};
  
int main()
{
    //DisjSet obj(100003);
    int n,m,i,len;
    cin>>n>>m;
    char s1[]="JOIN",s2[]="FIND";
    DisjSet obj(n);
    for(i=1;i<=m;i++)
    {
        char chk[5];
        int per1,per2;
        cin>>chk>>per1>>per2; 
    
        if(strcmp(chk,s1)==0)
        {
            obj.Union(per1,per2);
        }
        else if(strcmp(chk,s2)==0)
        {
            if(obj.find(per1)==obj.find(per2))
            {
                cout<<"Yes\n";
            }
            else{
                cout<<"No"<<endl;
            }
        }
        
    }
    
    return 0;
}