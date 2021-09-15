### __Longest Substring With Exactly K Unique Characters__
[Problem Link](https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/hashmap-and-heaps/longest-substring-with-exactly-k-unique-characters-official/ojquestion)

1. You are given a string(str) and a number K.
2. You have to find length of the longest substring that has exactly k unique characters.
3. If no such substring exists, print "-1".

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
    
    int c=0;
    int max_l=-1;
    while(end<s.length())
    {
        u[s[end]]++;
        if(u[s[end]]==1)c++;
        
      while(c>k&&start<end)
      {
          if(u[s[start]]==1) c--;
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
