__Shortest Subarray with Sum at Least K__ 

[Problem Link](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k)

![image](https://user-images.githubusercontent.com/51910127/134007144-a41e6364-edd4-4d6b-9806-2519d20dfea2.png)
![image](https://user-images.githubusercontent.com/51910127/134007188-2b994bcb-767d-460e-9270-d2055dacd382.png)


### __Sliding window will not work here: see below test case__
![image](https://user-images.githubusercontent.com/51910127/133998664-f0719769-c84f-4e93-a345-f63d58b05dad.png)

Reason :
When we adjust the right or left boundary of the sliding window, we don't know when should we extend to right and when should shrink left. Increase right pointer doesn't necessarily increase sum and also increase left pointer doesn't necessarily decrease the sum, thus we can't apply the simple slide window check logic here.


__WRONG SLIDING WINDOW SOLUTION__
```cpp
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
      int sh=INT_MAX;
        int start=0, end=0,csum=0;
        while(end<nums.size())
        {
            csum=csum+nums[end];
            while(start<=end&& csum>=k)
            {
                csum=csum-nums[start];
                sh=min(sh, end-start+1);
                start++;
                
            }
            end++;
            
            
        }
        if(sh==INT_MAX) return -1;
        return sh;
    }
};

```


