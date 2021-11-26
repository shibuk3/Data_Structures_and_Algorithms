### __Next Permutation__

![image](https://user-images.githubusercontent.com/51910127/143613073-75ea5b16-f6c2-4f3e-abe6-b9684eff3117.png)
![image](https://user-images.githubusercontent.com/51910127/143613099-e743d262-daa8-4dbc-8d9b-457ef0638688.png)



- [Question link](https://leetcode.com/problems/next-permutation/)
- [Explaination video](https://www.youtube.com/watch?v=LuLCLgMElus)

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), k, l;
    	for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
    	if (k < 0) {
    	    reverse(nums.begin(), nums.end());
    	} else {
    	    for (l = n - 1; l > k; l--) {
                if (nums[l] > nums[k]) {
                    break;
                }
            } 
    	    swap(nums[k], nums[l]);
    	    reverse(nums.begin() + k + 1, nums.end());
        }
    }
};
```
