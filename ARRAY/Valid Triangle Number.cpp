/*
611. Valid Triangle Number
Medium
Given an integer array nums, return the number of triplets chosen
from the array that can make triangles if we take them as side 
lengths of a triangle.
 
Example 1:
Input: nums = [2,2,3,4]
Output: 3
Explanation: Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
Example 2:
Input: nums = [4,2,3,4]
Output: 4
 
Constraints:
1 <= nums.length <= 1000
0 <= nums[i] <= 1000
Solution Explianation
Credits- Leetcode Discuss
------------------------------------------------------------------------------------------------------------
I'm a little bit late, but I'll comment in case anyone else is wondering why this works and why
the author did a right to left algorithm instead of left to right. It's because the idea is
to convert this into 3-sum, which is a staple problem. This is due to a loophole with the 
triangle inequality which states that:
a + b > c
a + c > b
b + c > a
must all hold for these 3 line segments to form a triangle.
Now, if we assume without loss of generality that a < b < c, then we already
know that a + c > b and b + c > a MUST hold because we have that c is inherently
greater than both b and a. This is why the author starts from the end of the array,
rather than the beginning of it. The target to beat is the high point. If you try
something left to right, you're going to end up overcounting. Of course, you 
could just sort in descending order, then run the algorithm left to right instead.
That leaves the question then, which values make a + b > c work? Now this
problem is basically 3-sum. We want to start with as low a bound as possible,
and as high a bound as possible, and if we have a find that a + b > c, then
we know b paired with a, or any number after a will work, and hence, we get
that whole range of numbers as valid choices. We then lower the bound.
Likewise, if a + b < c, then our try is too low and the only way to get
closer to having a + b > c from where we're at is to increase the lower
bound. In the case a + b == c, it's arbitrary which we change, the lower
bound or the upper bound.
*/
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count =0;
        for(int i=nums.size()-1;i>1;i--)
        {   int end= i-1, start=0; 
             
            while(start<end)
            {
                if(nums[start]+nums[end]>nums[i]) /// why we have started from last 
                {count+=end-start; end--;}/////// trickiest here check why it is  end--
                else
                    start++;  /////// check here why it is start ++
                
            }
            
            
        }
       return count; 
    }
};
