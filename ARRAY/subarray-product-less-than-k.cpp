/*
713. Subarray Product Less Than K
Medium
Given an array of integers nums and an integer k, 
return the number of contiguous subarrays where the
product of all the elements in the subarray is strictly less than k.
 
Example 1:
Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
Example 2:
Input: nums = [1,2,3], k = 0
Output: 0
 
Constraints:
1 <= nums.length <= 3 * 104
1 <= nums[i] <= 1000
0 <= k <= 106
 condsider this array[a, b, c,d]
 lets introduce another elemet 'e'
 the new subarray creation due to introduction of e is
 
 1) [a,b,c,d,e]
 2) [b,c,d,e]
 3) [c,d,e]
 4) [d,e]
 5) [e]
  at each step this new subaarray arae created which is
  equal to size of array (after introduction of e) 
  size= end- start+1
*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count=0;
int prod=1;        
        int end=0, start=0;
        while(end<nums.size())
        { prod*=nums[end];
          while(end>=start && prod>=k)
          {
              prod=prod/nums[start];
              
            start++;  
          }
           count+=end-start+1; //// trickiest part
         end++;
        }
        
        return count;
    }
};
