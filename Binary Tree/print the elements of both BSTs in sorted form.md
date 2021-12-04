### __print the elements of both BSTs in sorted form(https://leetcode.com/problems/all-elements-in-two-binary-search-trees/)__

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
__Solution 1: Three pass solution , TC=O(m+n), SC=O(m+n)__
```cpp
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2, ret;
        if (root1) dfs(root1, v1);
        if (root2) dfs(root2, v2);
        int pos1 = 0, pos2 = 0;
        while (pos1 < v1.size() && pos2 < v2.size())
        {
            if (v1[pos1] < v2[pos2]) ret.push_back(v1[pos1++]);
            else ret.push_back(v2[pos2++]);
        }
        while (pos1 < v1.size()) ret.push_back(v1[pos1++]);
        while (pos2 < v2.size()) ret.push_back(v2[pos2++]);
        return ret;
    }
    void dfs(TreeNode* root, vector<int>& v)
    {
        if (root->left) dfs(root->left, v);
        v.push_back(root->val);
        if (root->right) dfs(root->right, v);
    }
};
```




__Solution 2 : One pass solution, TC=O(m+n), SC=O(H)  , in worst case height of tree can be H=N__ 
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
