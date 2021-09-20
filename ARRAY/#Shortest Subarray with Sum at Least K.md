__Shortest Subarray with Sum at Least K__
[Problem Link](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k)

### __Sliding window will not work here: see below test case__
![image](https://user-images.githubusercontent.com/51910127/133998664-f0719769-c84f-4e93-a345-f63d58b05dad.png)

Reason :
When we adjust the right or left boundary of the sliding window, we don't know when should we extend to right and when should shrink left. Increase right pointer doesn't necessarily increase sum and also increase left pointer doesn't necessarily decrease the sum, thus we can't apply the simple slide window check logic here.

