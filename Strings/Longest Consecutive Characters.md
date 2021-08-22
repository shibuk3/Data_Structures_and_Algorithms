### __Consecutive Characters__
[Problem Link](https://leetcode.com/problems/consecutive-characters/)

The power of the string is the maximum length of a non-empty substring that contains only one unique character. \
Given a string s, return the power of s.

 

__Example 1:__

Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.

__Example 2:__

Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.

__Example 3:__

Input: s = "triplepillooooow"
Output: 5

__Example 4:__

Input: s = "hooraaaaaaaaaaay"
Output: 11

__Example 5:__

Input: s = "tourist"
Output: 1
 

__Constraints:__

- 1 <= s.length <= 500
- s consists of only lowercase English letters.

```cpp
class Solution {
public:
    int maxPower(string s) {
        int end=0, len=INT_MIN, count=0;
        char prev=s[end], cur=s[end];
        while(end<s.length())
        {
            if(s[end]==prev)
            { count++;len=max(len,count);}
            else
            {count=1;prev=s[end]; }
            end++;
            
        }
        return len;
    }
};
```
