### __Square root of a number__
```md
__Concept:__ This problem's key point is that we want to find the largest number, which num*num <= x, 
therefore we should use the binary search to find the upper bound within the range(1,x).
Different people may have their own way handling the boundaries, but I figure we'd better
think clearly what we want to find through binary search.
Below is my code, just a typical template of using upper bound of binary search
```


```cpp
class Solution {
    public int mySqrt(int x) {
        int i = 1;
        int j = x;
        int ans = 0;
        while (i <=j){
            int mid = i + (j-i)/2;
            // upper bound
            if (mid <= x/mid){
                i = mid +1;
                ans = mid;
            }
            else
                j = mid-1;
        }
        
        return ans;
    }
}
```
