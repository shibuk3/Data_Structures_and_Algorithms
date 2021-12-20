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

### __Uglu Numbers II__
- [explaination video](https://www.youtube.com/watch?v=Lj68VJ1wu84)

```md
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

 

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
 

Constraints:

1 <= n <= 1690
```

```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int >ans;
        ans.push_back(1);
        int i=0, j=0, k=0;
        while(ans.size()<n)
        {
            ans.push_back(min(2*ans[i],min(3*ans[j], 5*ans[k])));
            if(ans.back()==2*ans[i]) i++;
            if(ans.back()==3*ans[j]) j++;
            if(ans.back()==5*ans[k]) k++;
            
        }    
            return ans.back();
    }
};
```
