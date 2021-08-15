/*
1099. Two Sum Less Than K (https://leetcode.com/problems/two-sum-less-than-k/): Given an array A of integers and integer K, 
return the maximum S such that there exists i < j with A[i] + A[j] = S and S < K.
If no i, j exist satisfying this equation, return -1.
1099. Two Sum Less Than K (#1 Sort + Two pointer).java
*/


// Sort + Two pointer solution
// Time: O(nlogn), 1ms
// Space: O(1), 36.7mb
class Solution {
    public int twoSumLessThanK(int[] A, int K) {
        // Sort the array first
        Arrays.sort(A);
        
        // Put pointers at begin/end and shrink
        int l = 0, r = A.length - 1;
        int ans = -1;
        while(l < r) {
            if(A[l] + A[r] < K) {
                ans = Math.max(ans, A[l] + A[r]);
                l++;
            } else {
                r--;
            }
        }
        
        return ans;
    }
}
