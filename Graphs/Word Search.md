```md
Given an m x n grid of characters board and a string word, return true if
word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells,
where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
 

Follow up: Could you use search pruning to make your solution faster with a larger board?
```

### MY solution dfs+backtracking:248 ms, Sc=(m*n)
```cpp
bool safe(int m, int n, int x, int y,vector<vector<int>>& vis)
{
    if(x<0||x>=m||y<0||y>=n||vis[x][y]==1) return false;
    
    else
        return true;
}
bool find(vector<vector<char>>& board, string& word, int m, int n, int curx, int cury,vector<vector<int>>& vis, int pos)
{  if(word[pos]=='#') return true;
   
    if(safe(m,n,curx,cury,vis)&&board[curx][cury]==word[pos])
    {    vis[curx][cury]=1;
        if(find(board,word,m,n,curx+1,cury,vis,pos+1))     return true;
        else if(find(board,word,m,n,curx-1,cury,vis,pos+1))return true;
        else if(find(board,word,m,n,curx,cury+1,vis,pos+1))return true;
        else if(find(board,word,m,n,curx,cury-1,vis,pos+1))return true;
     else 
     {vis[curx][cury]=0;  // very imp  
         return false;}  
        
    }
    
    return false;
    
}


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
         word.push_back('#');
        int m=board.size();
        int n=board[0].size();
            vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i =0;i<m;i++)
            for(int j =0;j<n;j++)
               if(word[0]==board[i][j]&&find(board, word,m, n, i, j,vis, 0))return true;
        
        
        return false;
    }
};
````
### Efficient solution: 19ms , SC(no extra space except data recursion space)
```cpp

bool exist(vector<vector<char>>& board, string word) {
    for (unsigned int i = 0; i < board.size(); i++) 
        for (unsigned int j = 0; j < board[0].size(); j++) 
            if (dfs(board, i, j, word))
                return true;
    return false;
}

bool dfs(vector<vector<char>>& board, int i, int j, string& word) {
    if (!word.size())
        return true;
    if (i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] != word[0])  
        return false;
    char c = board[i][j];
    board[i][j] = '*';
    string s = word.substr(1);
    bool ret = dfs(board, i-1, j, s) || dfs(board, i+1, j, s) || dfs(board, i, j-1, s) || dfs(board, i, j+1, s);
    board[i][j] = c;
    return ret;
}
```
