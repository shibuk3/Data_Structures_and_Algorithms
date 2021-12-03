### __Majority Element : frequncy > floor of N/2__

- [Practise link](https://leetcode.com/problems/majority-element/)
- [Explaination video , Intution](https://www.youtube.com/watch?v=AoX3BPWNnoE)

```md
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times.
You may assume that the majority element always EXISTS in the array,

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-231 <= nums[i] <= 231 - 1
 

Follow-up: Could you solve the problem in linear time and in O(1) space?
```
### __Solutions__
- Brute force TC=O(N^2)
- hash map based TC=O(NlogN)
- Optimal TC=O(N), SC=O(1), based on MOORE's Voting algo

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=-1;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {  
            
            if(ans==nums[i]) count++;
            else if(count==0) ans=nums[i];
              else 
                  count--;
     
        }
        return ans;
            
    }
};
```
