/*
Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.
 k can also be zero
Example 1:
Input: nums = [1,1,1], k = 2
Output: 2
Example 2:
Input: nums = [1,2,3], k = 3
Output: 2
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        
        unordered_map<int, int> u;
        int ans=0;
        int sum= 0;
        
        for(int i=0;i<nums.size();i++)
        {  sum=sum+nums[i];
           if(sum==k) ans++;
          
         if(u.find(sum-k)!=u.end()) {ans+=u[sum-k] ;}
          u[sum]++;
         
          
          
            
            
        }
       return ans; 
    }
};
