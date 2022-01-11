### __Palindrome Pairs__
- [LC link](https://leetcode.com/problems/palindrome-pairs/)
```md
Given a list of unique words, return all the pairs of the distinct 
indices (i, j) in the given list, so that the concatenation of the
two words words[i] + words[j] is a palindrome.

 

Example 1:

Input: words = ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]]
Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
Example 2:

Input: words = ["bat","tab","cat"]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["battab","tabbat"]
Example 3:

Input: words = ["a",""]
Output: [[0,1],[1,0]]
 

Constraints:

1 <= words.length <= 5000
0 <= words[i].length <= 300
words[i] consists of lower-case English letters.
```

Solution giving TLE: 134/136 cases passed Hash map solution , TRIE based solution could work
```cpp
 string find(string x)
  {
      
      reverse(x.begin(), x.end());
      
      return x;
  }

bool isplain(string &x)
{
    int i=0; int j=x.length()-1;
    while(i<j){
       if(x[i]!=x[j])  return false;
           i++;j--;}
    
    return true;
}

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<string, int>u;
        
        for(int i=0;i<words.size();i++) u[words[i]]=i;
        
        if(u.find("")!=u.end())
        { int ind=u[""];
            for(int i=0;i<words.size();i++)
        {   
           if(i!=ind&&isplain(words[i])) 
           {ans.push_back({i,ind,});
            ans.push_back({ind,i});} 
        }   
        }
        
        for(int i=0;i<words.size();i++)
        {
            string x= find(words[i]);
          //  int g=u[x];
            if(u.find(x)!=u.end()&&u[x]!=i)
            {
                int ind=u[x];
                ans.push_back({i, ind});
            }
            
        }
        
         for(int i=0;i<words.size();i++)
        {      int len=words[i].length();
            for(int j=0;j<len-1;j++)
        { 
             string x1=words[i].substr(0,j+1);
               
                
                string y=words[i].substr(j+1);
               
                
              
                if(isplain(y))
                {
                    string xdash1=find(x1);
                 if(u.find(xdash1)!=u.end())
                    ans.push_back({i,u[xdash1]});
                 
                }
            
        
         
               if(isplain(x1)){
               string ydash=find(y);
                if(u.find(ydash)!=u.end() )
                    ans.push_back({u[ydash],i});
               }
        }
            
         
         
         
         
         
        }
        return ans;
        
        
    }
};
```
