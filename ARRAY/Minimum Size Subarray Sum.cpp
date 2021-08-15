/*
Given an array of __POSITIVE INTEGERS__ nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.
 DO NOT work if elements are negative
Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:
Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
if(nums.size()==0) return 0;
        int n=nums.size();
 int start=0, end=0, sum=0, len=INT_MAX;
        
        while(end<nums.size())
        {
            if(sum<target)    sum+=nums[end];
            while(sum>=target &&start<=end)
            {
                if(len>end-start) len=end-start+1;
                 sum-=nums[start++];
            } 
            end++;
        }
    if (len==INT_MAX) return 0;
     return len;
    }
};
