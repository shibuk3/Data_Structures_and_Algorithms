### __Longest Substring With Non Repeating Characters__
[Problem Link](https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/hashmap-and-heaps/longest-substring-with-unique-characters-official/ojquestion)
1. You are given a string.
2. You have to find the length of the longest substring of the given string that contains all non-repeating characters.

```cpp
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main()
{   string s;
    cin>>s;
    int k;
    cin>>k;
    
    unordered_map<char, int>u;
    
    int end=0, start=0;
    
    bool t=false;
    int max_l=INT_MIN;
    while(end<s.length())
    {
        u[s[end]]++;
        if(u[s[end]]==2)t= true;
        
      while(t&&start<end)
      {
          if(u[s[start]]==2) t=false;
          u[s[start]]--;
          
          start++;
      }
        
        
        max_l=max(max_l,end-start+1);
        end++;
        
        
    }
    cout<<max_l;
    
    return 0;
}
```
