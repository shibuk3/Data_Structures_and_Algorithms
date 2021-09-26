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
