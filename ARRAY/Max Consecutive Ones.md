### __Max Consecutive Ones__

Given a binary array nums, return the maximum number of consecutive 1's in the array.

 

Example 1:

Input: nums = [1,1,0,1,1,1] \
Output: 3 \
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3. \
Example 2: 

Input: nums = [1,0,1,1,0,1] \
Output: 2
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.

```cpp

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int end=0,  mx=0, count=0;
        while(end<nums.size())
        {  
            
            
            
            if(nums[end]==1)
            {count++;  mx=max(mx,count);}
              else
              {count=0;}
            
            end++;
            
        }
        return mx;
    }
};

```
