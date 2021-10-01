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
 
