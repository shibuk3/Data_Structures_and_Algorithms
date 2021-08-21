### __Swap For Longest Repeated Character Substring__
[Problem Link](https://leetcode.com/problems/swap-for-longest-repeated-character-substring/) \
Given a string text, we are allowed to swap two of the characters in the string.\
Find the length of the longest substring with repeated characters.

 

__Example 1:__

Input: text = "ababa"
Output: 3
Explanation: We can swap the first 'b' with the last 'a', or the last 'b' with the first 'a'. \
 Then, the longest repeated character substring is "aaa", which its length is 3.

__Example 2:__

Input: text = "aaabaaa"
Output: 6
Explanation: Swap 'b' with the last 'a' (or the first 'a'), and we get longest repeated \
character substring "aaaaaa", which its length is 6.

__Example 3:__

Input: text = "aaabbaaa"
Output: 4

__Example 4:__

Input: text = "aaaaa"
Output: 5
Explanation: No need to swap, longest repeated character substring is "aaaaa", length is 5.

__Example 5:__

Input: text = "abcdef"
Output: 1
 

__Constraints:__

- 1 <= text.length <= 20000
- text consist of lowercase English characters only.

### __Explaination__
Instead of going through the whole string 26 times, we first collect indexes for each character.\
Then we process each character and use its indexes to determine the longest substring.

In the solution below, we count the number of consecutive indices cnt, and track the number of\
previous consecutive indices cnt1.

__Note:__ that we set cnt1 to zero if the gap is larger than one.

In the end, we'll get a max count of the repeated characters with no more than one-character gap.\
If we have more of that character somewhere in the string (idx[n].size() > mx), we add 1 for the swap operation.


```cpp
int maxRepOpt1(string text, int res = 1) {
  vector<vector<int>> idx(26);
  for (auto i = 0; i < text.size(); ++i) idx[text[i] - 'a'].push_back(i);
  for (auto n = 0; n < 26; ++n) {
    auto cnt = 1, cnt1 = 0, mx = 0;
    for (auto i = 1; i < idx[n].size(); ++i) {
      if (idx[n][i] == idx[n][i - 1] + 1) ++cnt;
      else {
          cnt1 = idx[n][i] == idx[n][i - 1] + 2 ? cnt : 0;
          cnt = 1;
      }
      mx = max(mx, cnt1 + cnt);        
    }
    res = max(res, mx + (idx[n].size() > mx ? 1 : 0));
  }
  return res;
}
```
