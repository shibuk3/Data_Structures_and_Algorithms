### __Number of Matching Subsequences__
- [LC Link](https://leetcode.com/problems/number-of-matching-subsequences/)

```md
Given a string s and an array of strings words, return the number
of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with
some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
 

Example 1:

Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
Example 2:

Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2
 

Constraints:

1 <= s.length <= 5 * 104
1 <= words.length <= 5000
1 <= words[i].length <= 50
s and words[i] consist of only lowercase English letters.
```

My solution : TLE , alyhough logic is correct 42/52 cases passed
```cpp
bool search(vector<int> &temp ,int& prev)
{  int ans=INT_MIN;
    int high= temp.size()-1;
    int low=0;
    while(low<=high)
    {
      int mid=(high+low)/2;
        
       
        if(temp[mid]>prev)
        { ans=temp[mid]; high=mid-1;}
        else 
            low =mid+1;
        
        
    }
 
  if(ans==INT_MIN) return false;
   else 
   {prev=ans;return true;}
    
}
bool find(string &x, vector<vector<int>>&u)
{ int  prev=-1;
   for(int i=0;i<x.length();i++){
    vector<int> temp= u[x[i]-'a'];
     if(!search(temp, prev))
         return false;
    
    
   }
    return true;
}

class Solution {
public:
    int numMatchingSubseq(string &s, vector<string>& words) {
    //  unordered_map<char, vector<int>>u;
        vector<vector<int>> v(26);
        
        for(int i=0;i<s.length();i++) v[s[i]-'a'].push_back(i);
        int ans=0; int prev=-1;
        for(int i=0;i<words.size();i++)
        {  
            if(find(words[i],v)) ans++;
        }
        return ans;
    }
};
```
