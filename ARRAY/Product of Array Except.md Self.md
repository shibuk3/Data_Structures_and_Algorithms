### __Product of Array Except Self__
[Problem Link](https://leetcode.com/problems/product-of-array-except-self/)

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
![image](https://user-images.githubusercontent.com/51910127/132986707-7e570947-b97d-4568-901c-c6161a6ebc96.png)

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       vector<int> left(nums.size(),0);
        vector<int> right(nums.size(),0);
        left[0]=1;right[nums.size()-1]=1;
        for(int i=1;i<nums.size();i++ )
            left[i]=left[i-1]*nums[i-1];
        
        for(int i=nums.size()-2;i>=0;i--)
            right[i]=right[i+1]*nums[i+1];
        
        vector<int> out;
        for(int i=0;i<nums.size();i++)           out.push_back(left[i]*right[i]);
        
        return out;
    }
};
```
### __Follow up__
Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)
[Video Link](https://www.youtube.com/watch?v=tSRFtR3pv74&list=WL&index=186)
```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      // vector<int> left(nums.size(),0);
        vector<int> out(nums.size(),0);
        out[0]=1;
        for(int i=1;i<nums.size();i++ )
            out[i]=out[i-1]*nums[i-1];
        
        int g=1;
        for(int i=nums.size()-2;i>=0;i--)   
        {out[i]=g*nums[i+1]*out[i];
        g=g*nums[i+1];
        }
        return out;
    }
};
```

