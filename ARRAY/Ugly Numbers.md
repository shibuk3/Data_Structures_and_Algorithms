### __Ugly Numbers__

- [LC Link](https://leetcode.com/problems/ugly-number/)
```
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return true if n is an ugly number.
Example 1:

Input: n = 6
Output: true
Explanation: 6 = 2 × 3
Example 2:

Input: n = 8
Output: true
Explanation: 8 = 2 × 2 × 2
Example 3:

Input: n = 14
Output: false
Explanation: 14 is not ugly since it includes the prime factor 7.
Example 4:

Input: n = 1
Output: true
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
 

Constraints:

-231 <= n <= 231 - 1
```
```cpp

class Solution {
public:
    bool isUgly(int x) {
        if(x==0) return false;
  if(x==1) return true;
        while(x%2==0)x=x/2;
        if(x==1) return true;
    while(x%3==0)x=x/3;
        if(x==1) return true;
        while(x%5==0)x=x/5;
    if(x==1) return true;
        else return false;
  
    }
};
```
