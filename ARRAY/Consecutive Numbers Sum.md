###  __Consecutive Numbers Sum__
[Problem Link](https://leetcode.com/problems/consecutive-numbers-sum/) \
Given an integer n, return the number of ways you can write n as the sum of consecutive positive integers.
![image](https://user-images.githubusercontent.com/51910127/132951382-be864b47-0160-42e6-9308-d9db3243e1dd.png)

```cpp
class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int count = 1;
        for( int k = 2; k < sqrt( 2 * N ); k++ ) {
            if ( ( N - ( k * ( k - 1 )/2) ) % k == 0) count++;
        }
        return count;
    }
};

```

Assume k consecutive numbers:  \
x + (x+1) + (x+2)+...(x+k-1) = N, \
=> kx + k*(k-1)/2 = N \
=> k(k-1+2x) = 2N \
As we know x is positive number, so x>=1 \
=> 2N-k^2 = k(2x-1)>0 \
=> 2N>k^2 \
so k is limited to k<sqrt(2*N). 
