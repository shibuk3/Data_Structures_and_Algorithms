- [find kth smallest elemnt in bst , withput traversing the whole tree , TC=O(h)](https://www.geeksforgeeks.org/find-k-th-smallest-element-in-bst-order-statistics-in-bst/)
- [find Sum of k smallest elements in BST,  TC=O(h)](https://www.geeksforgeeks.org/sum-k-smallest-elements-bst/)
- [Inorder Tree Traversal without Recursion, using stack](https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/)
- [Inorder Tree Traversal without recursion and without stack!](https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/)
- [left view of binary tree without level order traversal](https://www.geeksforgeeks.org/print-left-view-binary-tree/)
- [__Morris Order Traversal:__  Inorder and Preorder Traversal without recursion and stack](https://www.youtube.com/watch?v=wGXB9OWhPTg) \
 -- [code link for morris traversal](https://github.com/mission-peace/interview/blob/master/src/com/interview/tree/MorrisTraversal.java)
- [Rainwater trapping problem with and without using stack, TC=O(n), SC=O(1) ](https://www.geeksforgeeks.org/trapping-rain-water/)
--[video link](https://www.youtube.com/watch?v=m18Hntz4go8)
- [Find Excel column name from a given column number](https://www.geeksforgeeks.org/find-excel-column-name-given-number/)
- [Find minimum number of steps to make the product of all the elements of the array 1, by incresing or decreasing the element of array by 1 in one step](https://www.youtube.com/watch?v=mPPNFyBNyJY&list=WL&index=172&t=1212s)
- [Minimum Number of Platforms Required for a Railway/Bus Station](https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/)
- bottom/ right view of binary tree
- There are N gas stations along a circular route, where the amount of gas
at the ith station is gas[i].  You have a car with an unlimited gas tank 
and it costs cost[i] of gas to travel from the ith station to its next 
i + 1) th station. You begin the journey with an empty tank at one of
 the gas stations. Given two integer arrays gas and cost, return the starting gas station.
 - [Bottom view of binary tree in both BFS and DFS.](https://www.geeksforgeeks.org/bottom-view-of-a-binary-tree-using-recursion/)
 
 
### __HARD___
- [Given a number in words, print the number](https://www.geeksforgeeks.org/convert-number-to-words/)
- [given a number, convert into words](https://www.geeksforgeeks.org/program-to-print-the-given-digit-in-words/)
### __DP__
- [Assembly Line Scheduling](https://www.geeksforgeeks.org/assembly-line-scheduling-dp-34/)


### __AMAZON LATEST OA__
- https://leetcode.com/discuss/interview-question/1486822/AMAZON-OA-or-BangaloreIndia-or-SDE-2
- https://leetcode.com/problems/coin-change-2/
- ![image](https://user-images.githubusercontent.com/51910127/135668222-0390a21e-6c40-4dd8-9705-7a9d59ba2680.png)
![image](https://user-images.githubusercontent.com/51910127/135668321-ea0777f4-fd0f-4c2e-91ab-591a8bae3854.png)
![image](https://user-images.githubusercontent.com/51910127/135668359-c7f5a4e4-9634-488a-87da-71bc10529e56.png)

```java
public static long carParkingRoof(List<Long> cars, int k) {
    // Write your code here
        if (cars.size() == 0 || k < 0) {
            return 0;
        }

        Collections.sort(cars);
        long minDist = Long.MAX_VALUE;

        for (int i = 0; i <= cars.size() - k; i++) {
            minDist = Math.min(minDist, cars.get(i + k - 1) - cars.get(i));
        }

        return minDist + 1;
    }
```
 ```md
 Given an integer array arr of size N and an integer S. Return the list of all pairs of
 elements such that for each sum of elements of each pair equals to S.
Note:

Each pair should be sorted i.e the first value should be less than or equals to the second value. 

Return the list of pairs sorted in non-decreasing order of their first value. In
case if two pairs have the same first value, the pair with a smaller second value
should come first.

Input Format:

The first line of input contains two space-separated integers N and S, denoting
the size of the input array and the value of S.

The second and last line of input contains N space-separated integers, denoting
the elements of the input array: arr[i] where 0 <= i < N.

Output Format:

 Print C lines, each line contains one pair i.e two space-separated integers,
 where C denotes the count of pairs having sum equals to given value S.

Constraints:

1 <= N <= 10^5
-10^5 <= A[i] <= 10^5
-2*10^5 <= S <= 2*10^5

Time Limit: 1 sec

Sample Input 1:

5 5
1 2 3 4 5

Sample Output 1:

1 4
2 3

Sample Input 2:

5 0
2 -3 3 3 -2

Sample Output 2:

-3 3
-3 3
-2 2
 ```
