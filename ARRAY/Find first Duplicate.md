### __Find first Duplicate__
[Problem Link](https://leetcode.com/problems/find-the-duplicate-number/)

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.
![image](https://user-images.githubusercontent.com/51910127/132913135-7f82bec2-0b5b-4893-a9de-d2f266f5f368.png)
![image](https://user-images.githubusercontent.com/51910127/132913189-e9c32a18-a724-48b5-b0e8-fe04420f58bc.png)

### hash solution (not good)
```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> u;
        
        
        for(int i=0;i<nums.size();i++)
        {
            if(u[nums[i]]==0) u[nums[i]]++;
            else
                return nums[i];
            
            
        }
        return -1;
    }
};
```
### 2ns soln- o(nlogn) binary serach based

This solution is based on binary search.

At first the search space is numbers between 1 to n. Each time I select a number mid (which is the one in the middle) and count all the numbers equal to or less than mid. Then if the count is more than mid, the search space will be [1 mid] otherwise [mid+1 n]. I do this until search space is only one number.

Let's say n=10 and I select mid=5. Then I count all the numbers in the array which are less than equal mid. If the there are more than 5 numbers that are less than 5, then by Pigeonhole Principle (https://en.wikipedia.org/wiki/Pigeonhole_principle) one of them has occurred more than once. So I shrink the search space from [1 10] to [1 5]. Otherwise the duplicate number is in the second half so for the next step the search space would be [6 10].

```py
class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        low = 1
        high = len(nums)-1
        
        while low < high:
            mid = low+(high-low)/2
            count = 0
            for i in nums:
                if i <= mid:
                    count+=1
            if count <= mid:
                low = mid+1
            else:
                high = mid
        return low
```
