//30
//30
//30
//30
//30
#include<iostream>
#include <list>
#include <limits.h>
using namespace std;
void insertionSort(int *A, int n){
    int key, j;
    // Loop for passes
    for (int i = 1; i <= n-1; i++)
    {
        key = A[i];
        j = i-1;
        // Loop for each pass
        while(j>=0 && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

class Graph
{
     
    // No. of vertices
    int V;  
   
    
    list<int> *adj; 
    bool isCyclicUtil(int v, bool visited[],
                              int parent);
public:
   
    // Constructor
    Graph(int V);  
   
    // To add an edge to graph
    void addEdge(int v, int w);
   
    // Returns true if there is a cycle
    bool isCyclic(); 
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
     
    // Add w to v’s list.
    adj[v].push_back(w);
   
    // Add v to w’s list.
    adj[w].push_back(v);
}
 
bool Graph::isCyclicUtil(int v,
                bool visited[], int parent)
{
     
    // Mark the current node as visited
    visited[v] = true;
 
    
    list<int>::iterator i;
    for (i = adj[v].begin(); i !=
                       adj[v].end(); ++i)
    {
         
       
        if (!visited[*i])
        {
           if (isCyclicUtil(*i, visited, v))
              return true;
        }
 
       
        else if (*i != parent)
           return true;
    }
    return false;
}
 

bool Graph::isCyclic()
{
     
    
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
   
    for (int u = 0; u < V; u++)
    {
       
        
        if (!visited[u])
          if (isCyclicUtil(u, visited, -1))
             return true;
    }
    return false;
}
 
// Driver program to test above functions
int main()
{
    long n,i;
    cin>>n;
    Graph g1(n);
    long m,x,y;
    cin>>m;
    for(i=0;i<m;i++){
        cin>>x>>y;
        g1.addEdge(x,y);
    }
    g1.isCyclic()?
       cout << "Yes\n":
       cout << "No\n";
 
 
    return 0;
}