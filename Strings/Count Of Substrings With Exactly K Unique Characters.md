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

### __Number of Matching Subsequences__

```md
Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

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
``` cpp
Solution 1: Brute force: TIME LIMIT EORROR ALTHOUGH THE SOLUTION IS CORRECT
bool check(string & s, string x)
{  int l=0;
    for(int i=0;i<s.length();i++) 
    {if(s[i]==x[l]) l++;
    
      if(l==x.length()) return true;
    }
 
    return false;
    
    
}


class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int count=0;
        for(int i=0;i<words.size();i++)
            if(check(s,words[i])) count++;
        
        return count;
    }
};

Solution 2: efficient approach

// General Idea:
    // - Brute force checking will time out, we need efficent way to look up words
    // - Create an vector that stores indices for each character a-z in S
    // - Then for each word, do a binary search for next index for current character in word 
    //   that is greater than the index we last found for the alst character
    // - If it doesn't exist, word doesn't exist, otherwise continue to search for word
    
	int numMatchingSubseq (string S, vector<string>& words) {
		vector<vector<int>> alpha (26);
		for (int i = 0; i < S.size (); ++i) alpha[S[i] - 'a'].push_back (i);
		int res = 0;

		for (const auto& word : words) {
			int x = -1;
			bool found = true;

			for (char c : word) {
				auto it = upper_bound (alpha[c - 'a'].begin (), alpha[c - 'a'].end (), x);
				if (it == alpha[c - 'a'].end ()) {found = false;break;}
				else x = *it;
			}

			if (found) res++;
		}

		return res;
	}

```
### __ubarrays with K Different Integers__

- [Lc Link](https://leetcode.com/problems/subarrays-with-k-different-integers/)
```md
Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
Example 2:

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
 

Constraints:

1 <= nums.length <= 2 * 104
1 <= nums[i], k <= nums.length
```

```cpp
int check(vector<int>& nums, int k)
{  unordered_map<int , int>u;
    int end=0, start=0;
    int ans=0;
    while(end<nums.size())
    {
        if(u.size()<=k)
            u[nums[end]]++;
 
        while(start<=end&&u.size()>k)
        {
            if(u[nums[start]]==1) u.erase(nums[start]);
            else
            u[nums[start]]--;
            start++;
        }
        
        ans+=end-start+1;
        end++;
        
    }
    
    
    return ans;
    
}

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
     return check(nums, k)-check(nums, k-1);   
    
```
