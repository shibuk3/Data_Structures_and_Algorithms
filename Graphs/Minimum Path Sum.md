### __Minimum Path Sum__

![image](https://user-images.githubusercontent.com/51910127/134724975-fdae9c39-1164-4812-bf9c-b436d033c6d8.png)

![image](https://user-images.githubusercontent.com/51910127/134724949-b780e563-fd59-4e0b-9eba-4485a23232c9.png)

```cpp
int find(vector<vector<int>>& grid, vector<vector<int>>& save, int x, int y, int m, int n)
{   if(x>=m||y>=n||x<0||y<0) return 0;
    
   if(save[x][y]!=-1) return save[x][y];
   
    save[x][y]=min(find(grid,save,x,y-1,m,n),find(grid,save,x-1,y,m,n))+grid[x][y];
    return save[x][y];  
}

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m= grid.size();
        int n=grid[0].size();
        vector<vector<int>> save(m,vector<int>(n,-1)) ;
        save[0][0]=grid[0][0];
        for(int i=1;i<m;i++) save[i][0]=save[i-1][0]+grid[i][0];
        //save[0][0]=grid[0][0];
        for(int i=1;i<n;i++) save[0][i]=save[0][i-1]+grid[0][i];
    return find(grid,save,m-1,n-1,m,n);
    }
};
```
