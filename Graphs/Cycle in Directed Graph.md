### __Cycle in Directed Graph__

![image](https://user-images.githubusercontent.com/51910127/134799155-da104f65-7cf2-4c45-8328-62e7f38d8b93.png)

```cpp
bool check(int cur, vector<bool>& visited,unordered_map<int, vector<int>>& u)
{
    
    if (visited[cur]) return true;
    visited[cur]=true;
    for(int i=0;i<u[cur].size();i++)
    {
        if(check(u[cur][i],visited,u))
           return true;
    }
    visited[cur]=false;
    
    
    return false;
    
}

int Solution::solve(int A, vector<vector<int> > &B) {
    
    unordered_map<int, vector<int>>u;
    
    for(int i=0;i<B.size();i++)  u[B[i][0]-1].push_back(B[i][1]-1);
    
    vector<bool>visited(A,false);
    for(int i=0;i<A;i++)
      {
          
          
          if(check(i,visited,u))
          return 1;
          
          
          
      }
      return 0;
}

```
