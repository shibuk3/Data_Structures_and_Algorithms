/*
https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1


Example 1:

Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
Example 2:

Input: nums = [5,6,7,8,9], x = 4
Output: -1
Example 3:

Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) { int sum=0;
        for(int i=0; i<nums.size();i++){sum+=nums[i];}
                                                 
           if(x>sum) return -1;
          int temp=0; int need=sum-x;
           if(need==0) return nums.size();
          unordered_map<int , int>u; int len=INT_MIN;                                       
      for(int i=0;i<nums.size();i++)
      {
          temp+=nums[i];
          
          if(temp==need) len=i+1;
          
          if(u.find(temp-need)!=u.end())
          len=max(len,i-u[temp-need]);
          
              if(u.find(temp)==u.end())
                u[temp]=i;
              
          
          
      }
                         if(len==INT_MIN) return -1;
                                                 else
                                                     return nums.size()-len;
                                                 
                                                 
    }
};
