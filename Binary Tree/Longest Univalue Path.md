687. Longest Univalue Path
Medium
[problem link](https://leetcode.com/problems/longest-univalue-path/)
Tags- HASHMAP, BINARY TREE, RECURSION, BACKTRACKING

Given the root of a binary tree, return the length of the longest path, where each
node in the path has the same value. This path may or may not pass through the root.

The length of the path between two nodes is represented by the number of edges
between them.

 

Example 1:
![image](https://user-images.githubusercontent.com/51910127/129801401-ed72dd87-4ab8-4fc6-bd61-1bda3b0442d0.png)



Input: root = [5,4,5,1,1,5]
Output: 2


Example 2:
![image](https://user-images.githubusercontent.com/51910127/129801436-0b8bab17-d876-436f-9520-5dcb74270a98.png)



Input: root = [1,4,5,4,4,5]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-1000 <= Node.val <= 1000
The depth of the tree will not exceed 1000.
### MY stupid ass find it hard, donot know why
solution credit: leetcode discuss
```cpp
int len = 0; // global variable
public int longestUnivaluePath(TreeNode root) {
    if (root == null) return 0;
    len = 0;
    getLen(root, root.val);
    return len;
}

private int getLen(TreeNode node, int val) {
    if (node == null) return 0;
    int left = getLen(node.left, node.val);
    int right = getLen(node.right, node.val);
    len = Math.max(len, left + right);
    if (val == node.val)  return Math.max(left, right) + 1;
    return 0;
}


```
