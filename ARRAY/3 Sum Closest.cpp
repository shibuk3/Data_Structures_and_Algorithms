/*
3Sum Closest
Medium
Given an integer array nums of length n and an integer target,
find three integers in nums such that the sum is closest to target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.
 
Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:
Input: nums = [0,0,0], target = 1
Output: 0
 
Constraints:
3 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
-104 <= target <= 104
*/


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans=INT_MAX; int sum=0;
      for(int i=0;i<nums.size()-2;i++)  
      {  
          
         int start=i+1, end=nums.size()-1;
          while(start<end)
          {
             if(nums[start]+nums[end]+nums[i]>target)
             {
                 if(ans>abs(nums[start]+nums[end]+nums[i]-target))
                 { ans=abs(nums[start]+nums[end]+nums[i]-target);
                   sum=nums[start]+nums[end]+nums[i];
                 }
                 
              end--;       
                     
                     
             }else if(nums[start]+nums[end]+nums[i]<target)
              { 
                 if(ans>abs(target-(nums[start]+nums[end]+nums[i])))
                { ans=abs(target-(nums[start]+nums[end]+nums[i]));
                   sum=nums[start]+nums[end]+nums[i];
                }
              start++;
              
              }
              else
                  return nums[start]+nums[end]+nums[i];
              
                 
          }
          
          

      
      }
      return sum;  
    }
};
