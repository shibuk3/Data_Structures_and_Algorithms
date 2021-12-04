### __print the elements of both BSTs in sorted form__

```md
Given two Binary Search Trees(BST), print the elements of both BSTs in sorted form.
The expected time complexity is O(m+n) where m is the number of nodes in the first 
tree and n is the number of nodes in the second tree. The maximum allowed auxiliary
space is O(height of the first tree + height of the second tree)

Examples:

First BST 
       3
    /     \
   1       5
Second BST
    4
  /   \
2       6
Output: 1 2 3 4 5 6


First BST 
          8
         / \
        2   10
       /
      1
Second BST 
          5
         / 
        3  
       /
      0
Output: 0 1 2 3 5 8 10 

```
```cpp
class Solution {
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        List<Integer> list = new ArrayList<>();
        Stack<TreeNode> st1 = new Stack<>();
        Stack<TreeNode> st2 = new Stack<>();
        pushLeft(root1, st1);
        pushLeft(root2, st2);
        
        while (!st1.isEmpty() || !st2.isEmpty()) {
            Stack<TreeNode> st = st2.isEmpty() || !st1.isEmpty() && st1.peek().val < st2.peek().val ? st1 : st2;
            TreeNode node = st.pop();
            list.add(node.val);
            pushLeft(node.right, st);
        }
        
        return list;
    }
    
    private void pushLeft(TreeNode node, Stack<TreeNode> st) {
        while (node != null) {
            st.push(node);
            node = node.left;
        }        
    }
}
```
