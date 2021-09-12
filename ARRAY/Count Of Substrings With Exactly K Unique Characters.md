
```cpp
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{   
    string s="aabcbcdbca";
 // cin>>s;
  int k=2;
 // cin>>k;
  
  int end=0, start=0;
  int count=0;
  unordered_map<char, int>u;
  int c=0;
  while(end<s.length())
  { 
    if(u[s[end]]==0){c++;u[s[end]]++;}
    
    while(c==k&&end+1<s.length()&&u[s[end+1]]!=0){count++;u[s[end]]++; end++;} 
    
    
    while(c==k &&start<end)   
      {  count++;
         if(u[s[start]]==1) c--;
          u[s[start]]--;
          start++;
          
          
      }
      end++;
  }
    
    cout<<count;
    
    return 0;
}
```
