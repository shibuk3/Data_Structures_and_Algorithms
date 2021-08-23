### __Count Number of Homogenous Substrings__
[Similar to Longest consective character](https://github.com/gauravkr0071/Data_Structures_and_Algorithms/blob/master/Strings/Longest%20Consecutive%20Characters.md) and [Max consecutive ones](https://github.com/gauravkr0071/Data_Structures_and_Algorithms/blob/master/ARRAY/Max%20Consecutive%20Ones.md) and [Number of Substrings With Only 1s](https://github.com/gauravkr0071/Data_Structures_and_Algorithms/blob/master/Strings/Number%20of%20Substrings%20With%20Only%201s.md)

[Problem Link](https://leetcode.com/problems/count-number-of-homogenous-substrings/)

Given a string s, return the number of __homogenous__ substrings of s. Since the answer may be too large, return it modulo __10^9 + 7.__

A string is __homogenous__ if all the characters of the string are the same.

A substring is a contiguous sequence of characters within a string.

 

__Example 1:__

Input: s = "abbcccaa" \
Output: 13 \
Explanation: The homogenous substrings are listed as below: \
"a"   appears 3 times. \
"aa"  appears 1 time. \
"b"   appears 2 times. \
"bb"  appears 1 time. \ 
"c"   appears 3 times.  \ 
"cc"  appears 2 times. \
"ccc" appears 1 time. \
3 + 1 + 2 + 1 + 3 + 2 + 1 = 13. 

__Example 2:__

Input: s = "xy" \
Output: 2 \
Explanation: The homogenous substrings are "x" and "y". \
__Example 3:__

Input: s = "zzzzz" \
Output: 15 
 

__Constraints:__

- 1 <= s.length <= 105
- consists of lowercase letters.

```cpp
class Solution {
public:
    int countHomogenous(string s) {
        int end=0, len=INT_MIN, count=0,mod = 1e9 + 7;
        char prev=s[end], cur=s[end];
        int c=0;
        while(end<s.length())
        {
            if(s[end]==prev)
            { count=count+1 ;}
            else
            { 
                
                count=1;
               
                prev=s[end]; }
                end++;
       c= (count+c)%mod;
             } 

        
        return c;
    }

        };
```
Explaination:
consider __aaaa__,count=0, c=0;  
- a count=1 \
    c=c+count--> c=1+0 
- aa  count=2 \
    c=c+count--> c=1+2  
- aaa count=3    \
     c=c+count--> c=3+3 
- aaaa count=4 \
     c=c+count--> c=6+4      
