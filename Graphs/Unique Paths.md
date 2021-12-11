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
__USE DP HERE: TC=O(M*N), SC=O(M*N) __

```cpp
int find(vector<vector<int>>& save, int m , int n, int i ,int j)
{
    if(i<0||j<0||i>m||j>n) return 0;
    
    if(save[i][j]!=-1) return save[i][j];
    if(i==0&&j==0) return 1;
    
    return save[i][j]=find(save,m,n,i,j-1)+find(save,m,n,i-1,j);

}

class Solution {
public:
    int uniquePaths(int m, int n) {
      vector<vector<int>> save(m, vector<int>(n,-1));
      return  find(save,m,n,m-1, n-1);
    }
};
```
### __Maths Solution__

```md
Solution 3: Math Solution

- There are total m+n-2 moves to go from Top-Left to Bottom-Right.
- In m+n-2 moves, there are m-1 down moves and n-1 right moves.
- You can imagine there are m+n-2 moves as: X X X ... X X X
X can be one of two values: down D or right R.
So, basically, it means we need to calculate how many ways we could choose m-1 
down moves from m+n-2 moves, or n-1 right moves from m+n-2 moves.
- So total ways = C(m+n-2, m-1) = C(m+n-2, n-1) = (m+n-2)! / (m-1)! / (n-1)!.


```
### __Unique paths 2__

- [LC LInk](https://leetcode.com/problems/unique-paths-ii/)

```md
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time.
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and space is marked as 1 and 0 respectively in the grid.

 

Example 1:


- Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
- Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
- 1. Right -> Right -> Down -> Down
- 2. Down -> Down -> Right -> Right
Example 2:


- Input: obstacleGrid = [[0,1],[0,0]]
- Output: 1
 

Constraints:

- m == obstacleGrid.length
- n == obstacleGrid[i].length
- 1 <= m, n <= 100
- obstacleGrid[i][j] is 0 or 1.

```
