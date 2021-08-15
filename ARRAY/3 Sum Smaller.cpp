/*
259: 3Sum Smaller
Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.
For example, given nums = [-2, 0, 1, 3], and target = 2.
Return 2. Because there are two triplets which sums are less than 2:
[-2, 0, 1]
[-2, 0, 3]
Follow up:
Could you solve it in O(n^2) runtime?
*/
public class Solution {
public int threeSumSmaller(int[] nums, int target) {
    int L = nums.length;
    Arrays.sort(nums);
    int count = 0;
    for(int i=0; i<L-2; i++) {
        int lo = i+1;
        int hi = L-1;
        while(lo<hi) {
            if(nums[i] + nums[lo] + nums[hi] < target) {
                count += hi-lo;
                lo++;
            }
            else
                hi--;
        }
    }
    return count;
}
}
