### __Cycle in Undirected Graph__

![image](https://user-images.githubusercontent.com/51910127/134799404-91b0f64f-34ec-4bc6-b666-aa48d2344908.png)
![image](https://user-images.githubusercontent.com/51910127/134799426-054f93f5-e34a-41b5-9772-d83f738b17be.png)
![image](https://user-images.githubusercontent.com/51910127/134799443-8ec0d5de-2292-4e1e-a038-4a82ba2de022.png)
![image](https://user-images.githubusercontent.com/51910127/134799448-56d71f23-bc8a-4af7-9fd7-f7a61e4a29be.png)
```cpp
bool fun(vector<bool>&visited,int cur,unordered_map<int, vector<int>>&g)
{
    queue<int>q;
    q.push(cur);
    vector<int> par(visited.size(),-1);
    visited[cur]=true;
   while(!q.empty())
   {
       
      int u=q.front(); q.pop();
       for(auto v :g[u])
       {
           
           if(!visited[v])
           {
               par[v]=u;visited[v]=true;
               q.push(v);
              
           }
           else if(par[u]!=v)
               return true;
           
       }
   }
   return false;
}


int Solution::solve(int A, vector<vector<int> > &B) {
    unordered_map<int, vector<int>>u;
    for(int i =0;i<B.size();i++) 
     {
        u[B[i][0]-1].push_back(B[i][1]-1);
    
        u[B[i][1]-1].push_back(B[i][0]-1);
        
    }
    vector<bool>visited (A,false);
    
    for(int i =0;i<A;i++)
    {
        if(!visited[i] &&fun(visited, i,u))
        return 1;

    }
    
    return 0;
    
}
```

```
// A C++ Program to detect 
// cycle in an undirected graph
#include<iostream>
#include <list>
#include <limits.h>
using namespace std;
  
// Class for an undirected graph
class Graph
{
      
    // No. of vertices
    int V;   
    
    // Pointer to an array 
    // containing adjacency lists
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
  
// A recursive function that 
// uses visited[] and parent to detect
// cycle in subgraph reachable 
// from vertex v.
bool Graph::isCyclicUtil(int v, 
                bool visited[], int parent)
{
      
    // Mark the current node as visited
    visited[v] = true;
  
    // Recur for all the vertices 
    // adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i !=
                       adj[v].end(); ++i)
    {
          
        // If an adjacent vertex is not visited, 
        //then recur for that adjacent
        if (!visited[*i])
        {
           if (isCyclicUtil(*i, visited, v))
              return true;
        }
  
        // If an adjacent vertex is visited and 
        // is not parent of current vertex,
        // then there exists a cycle in the graph.
        else if (*i != parent)
           return true;
    }
    return false;
}
  
// Returns true if the graph contains 
// a cycle, else false.
bool Graph::isCyclic()
{
      
    // Mark all the vertices as not 
    // visited and not part of recursion
    // stack
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
  
    // Call the recursive helper 
    // function to detect cycle in different
    // DFS trees
    for (int u = 0; u < V; u++)
    {
        
        // Don't recur for u if 
        // it is already visited
        if (!visited[u]) 
          if (isCyclicUtil(u, visited, -1))
             return true;
    }
    return false;
}
  
// Driver program to test above functions
int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isCyclic()? 
       cout << "Graph contains cycle\n":
       cout << "Graph doesn't contain cycle\n";
  
    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.isCyclic()? 
       cout << "Graph contains cycle\n":
       cout << "Graph doesn't contain cycle\n";
  
    return 0;
}
```
