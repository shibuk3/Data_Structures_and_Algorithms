# 3Sum
[Problem Link](https://leetcode.com/problems/3sum/description/)

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105

# Solution
```
class Solution {
public:
    void find(int index,vector<int>& nums,vector<vector<int>> &ans)
    {
        vector<int> sol;
        int i=index+1;
        int j=nums.size()-1;
        while(i<j)
        {
            if(nums[i]+nums[j]<(-nums[index]))
            {
                i++;
            }
            else if(nums[i]+nums[j]>(-nums[index]))
            {
                j--;
            }
            else
            {
                ans.push_back({nums[index],nums[i],nums[j]});
                i++;
                j--;
                while(i<nums.size() && nums[i-1]==nums[i]) i++;
                while(j>0 && nums[j+1]==nums[j]) j--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int i=0;
        while(i<nums.size()-2)
        {
            find(i,nums,ans);
            i++;
            while(i<nums.size() && nums[i-1]==nums[i]) i++;
        }
        return ans;
    }
};
```
