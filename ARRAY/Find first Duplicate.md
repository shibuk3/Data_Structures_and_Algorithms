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
