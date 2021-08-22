### __Max Consecutive Ones II__
[Problem Link](https://www.lintcode.com/problem/883/)

Given a binary array, find the maximum number of consecutive 1s in this array if you can flip at most one 0.

- The input array will only contain 0 and 1.
- The length of input array is a positive integer and will not exceed 10,000.
 
__Example 1:__
	Input:  nums = [1,0,1,1,0] \
	Output:  4 
	Explanation: 
	Flip the first zero will get the the maximum number of consecutive 1s. \
	After flipping, the maximum number of consecutive 1s is 4. \

__Example 2:__
	Input: nums = [1,0,1,0,1] \
	Output:  3 \
	Explanation: \
	Flip each zero will get the the maximum number of consecutive 1s. \
	After flipping, the maximum number of consecutive 1s is 3.
  
  ```cpp
  class Solution {
public:
    /**
     * @param nums: a list of integer
     * @return: return a integer, denote  the maximum number of consecutive 1s
     */
    int findMaxConsecutiveOnes(vector<int> &nums) {
          int count=0;
        int end=0, start=0, len=INT_MIN;
    while(end<nums.size())
    {  if(nums[end]==0) count++;
        while(start<=end && end<nums.size() && count>1)
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
	

