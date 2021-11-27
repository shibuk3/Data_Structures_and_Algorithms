### __Palindrome Partitioning__
![image](https://user-images.githubusercontent.com/51910127/143700622-54efe067-e5c5-4c53-bf4c-7d81be8b01ca.png)
![image](https://user-images.githubusercontent.com/51910127/143701009-8c514631-d9c9-489d-82cc-3f9788793823.png)

- [Explaination Video](https://www.youtube.com/watch?v=WBgsABoClE0)
- [Question link](https://leetcode.com/problems/palindrome-partitioning/)

```cpp
bool is_plain(string s,int start, int end )
{
    int n= s.length();
    while(start<=end)
    {if(s[start++]!=s[end--])  return false;}
    return true;
}

void helper(vector<vector<string>>& ans, string s,int start, int n, vector<string> temp )
{
    if(start==n) {ans.push_back(temp) ;return;}
    for(int i=start;i<n;i++){
    if(is_plain(s,start,i )) 
    {    
        temp.push_back(s.substr(start,i+1-start));
        helper(ans,s,i+1,n, temp);
        temp.pop_back();
    }
    }
    return;
}

class Solution {
public:
    vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
      vector<string> temp;
        helper(ans, s,0,s.length(), temp);
        return ans;
    }
};

```
```
TC= (2^n)*n* k (n  = length of substring) You can also just write exponential.
2^n for the recursion, *n for worst case palindrome check each time and k 
(size of DS) is for insertion in the final answer.

SC= And space complexbility will be n*k(where n is for vector insertion nd k is length of substring)
```
