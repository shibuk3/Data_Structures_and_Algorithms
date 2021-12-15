### __MY stupid Try__
[Problem link](https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/hashmap-and-heaps/count-of-substrings-with-exactly-k-unique-characters-official/ojquestion)   \
[Similiar question - https://leetcode.com/problems/subarrays-with-k-different-integers](https://leetcode.com/problems/subarrays-with-k-different-integers)
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
### __Sliding  Window Solution__

- No. of string that has exactly __K__ Distinct characters = No. of substing that has at most __K__ distinct characters - No. of substing that has at most __K-1__ distinct characters.
- No. of string that has exactly __K__ Distinct characters = No. of substing that has at least __K__ distinct characters - No. of substing that has at least  __K+1__ distinct characters.

```cpp
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int count(string s,int k )

{
 int end=0, start=0;
  
  unordered_map<char, int>u;int ans=0;
  int c=0;
  while(end<s.length())
  { 
    if(u[s[end]]==0){c++;}
    u[s[end]]++;
    
    
     
    
    
    while(c>k &&start<=end)   
      {  
 if(u[s[start]]==1) c--;                                                        
          u[s[start]]--;
          start++;
          
          
      }
      ans=ans+end-start+1;
      end++;
  }   
  
  return ans;
}


int main()
{   
    string s;
 cin>>s;
  int k;
 cin>>k;

  
  
    int ans=count(s,k)-count(s,k-1);
    cout<<ans;
    
    return 0;
}

```

### __Count Vowel Substrings of a String__

```md
A substring is a contiguous (non-empty) sequence of characters within a string.

A vowel substring is a substring that only consists of vowels ('a', 'e', 'i', 'o', and 'u') and has all five vowels present in it.

Given a string word, return the number of vowel substrings in word.

 

Example 1:

Input: word = "aeiouu"
Output: 2
Explanation: The vowel substrings of word are as follows (underlined):
- "aeiouu"
- "aeiouu"
Example 2:

Input: word = "unicornarihan"
Output: 0
Explanation: Not all 5 vowels are present, so there are no vowel substrings.
Example 3:

Input: word = "cuaieuouac"
Output: 7
Explanation: The vowel substrings of word are as follows (underlined):
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
Example 4:

Input: word = "bbaeixoubb"
Output: 0
Explanation: The only substrings that contain all five vowels also contain consonants, so there are no vowel substrings.
 

Constraints:

1 <= word.length <= 100
word consists of lowercase English letters only.
```
```cpp
Solution 1. Brute Force
// OJ: https://leetcode.com/problems/count-vowel-substrings-of-a-string/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    };
public:
    int countVowelSubstrings(string s) {
        int ans = 0, N = s.size();
        unordered_map<char, int> cnt;
        for (int i = 0; i < N; ++i) {
            cnt.clear();
            for (int j = i; j < N && isVowel(s[j]); ++j) {
                cnt[s[j]]++;
                if (cnt.size() == 5) ++ans;
            }
        }
        return ans;
    }
};
Solution 2. Sliding Window
Check out "C++ Maximum Sliding Window Cheatsheet Template!"

Function atMost(s, goal) returns the number of substrings that has at most goal number of unique vowels. The answer is atMost(s, 5) - atMost(s, 4).

// OJ: https://leetcode.com/problems/count-vowel-substrings-of-a-string/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    };
    int atMost(string &s, int goal) {
        int ans = 0, i = 0, j = 0, N = s.size();
        unordered_map<char, int> cnt;
        for (; j < N; ++j) {
            if (!isVowel(s[j])) {
                i = j + 1;
                cnt.clear();
                continue;
            }
            cnt[s[j]]++;
            for (; cnt.size() > goal; ++i) {
                if (--cnt[s[i]] == 0) cnt.erase(s[i]);
            }
            ans += j - i + 1; // this window [i, j] is the maximum window ending at `s[j]` that has at most `goal` number of unique vowels.
        }
        return ans;
    }
public:
    int countVowelSubstrings(string s) {
        return atMost(s, 5) - atMost(s, 4);
    }
};

```
