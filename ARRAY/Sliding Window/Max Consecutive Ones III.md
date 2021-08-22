### __Max Consecutive Ones III__
[Problem Link](https://leetcode.com/problems/max-consecutive-ones-iii/)

Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

__Example 1:__

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2 \
Output: 6 \
Explanation: [1,1,1,0,0,1,1,1,1,1,1] \
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined. \
__Example 2:__ 

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3 \
Output: 10  \
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]  \
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.  \
 

__Constraints:__

- 1 <= nums.length <= 105 
- nums[i] is either 0 or 1. 
- 0 <= k <= nums.length

```cpp
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
          int count=0;
        int end=0, start=0, len=INT_MIN;
    while(end<nums.size())
    {  if(nums[end]==0) count++;
        while(start<=end && end<nums.size() && count>k)
        {
             if(nums[start]==0)count--;
             start++;
        }
       
        
        if(len<end-start+1) len=end-start+1;
        
        
 end++;        
    }
        return len;
    }
};


```
