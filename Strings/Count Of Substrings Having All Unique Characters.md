### __Count Of Substrings Having All Unique Characters__

1. You are given a string.
2. You have to find the count of valid substrings of the given string.
3. Valid substring is defined as a substring that has all unique characters.

```cpp
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main()
{   string s;
    cin>>s;
    
    
    unordered_map<char, int>u;
    
    int end=0, start=0;
    
    
    int max_l=0;bool t=false;
    while(end<s.length())
    {
        u[s[end]]++;
        if(u[s[end]]>1)t=true;
        
      while(t&&start<end)
      {
          if(u[s[start]]>1) t=false;
          u[s[start]]--;
          
          start++;
      }
        
        
        max_l=max_l+end-start+1;
        end++;
        
        
    }
    cout<<max_l;
    
    return 0;
}
```
