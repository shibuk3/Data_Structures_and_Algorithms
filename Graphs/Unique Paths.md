### __Unique Paths__
[Problem Link](https://leetcode.com/problems/unique-paths/)

![image](https://user-images.githubusercontent.com/51910127/134729329-9461ab69-0f42-4c9a-89ea-100eebb96da0.png)
![image](https://user-images.githubusercontent.com/51910127/134729364-1459d267-c35d-4dac-8798-6dbaa4bf2aa6.png)

![image](https://user-images.githubusercontent.com/51910127/134729447-91a59004-116c-4139-8211-ed37f3cb6f1b.png)


__BFS Solution wont work here see constarints__
- As in each postion the path have two choices, so there are total 2^(n*n) paths

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        queue<pair<int, int>> q;
        
        int ans=0;
        q.push(make_pair(0,0));
        while(!q.empty())
        {
            pair<int, int>p= q.front();q.pop();
                        
            int x= p.first; int y=p.second;
            
            
            if(x==m-1&&y==n-1) ans++;
            if(x+1<=m-1&&y<=n-1)
            q.push(make_pair(x+1,y));
            if(x<=m-1&&y+1<=n-1)
            q.push(make_pair(x,y+1));
            
        }
        return ans;
    }
};
```
