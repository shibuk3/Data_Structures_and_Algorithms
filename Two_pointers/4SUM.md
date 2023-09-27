# 4SUM
[Problem Link](https://leetcode.com/problems/4sum/description/)
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
# Solution

```
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                long long int newTarget=(long long int)((long long int)(target-nums[i])-nums[j]);
                int l=j+1,m=n-1;
                while(l<m)
                {
                    if(nums[l]+nums[m]<newTarget)
                    {
                        l++;
                    }
                    else if(nums[l]+nums[m]>newTarget)
                    {
                        m--;
                    }
                    else
                    {
                        ans.push_back({nums[i],nums[j],nums[l],nums[m]});
                        l++,m--;
                        while(l<m && nums[l-1]==nums[l]) l++;
                        while(l<m && nums[m+1]==nums[m]) m--;
                    }
                }
                while(j<n-2 && nums[j+1]==nums[j]) j++;
            }
            while(i<n-3 && nums[i+1]==nums[i]) i++;
        }
        return ans;
    }
};
```
