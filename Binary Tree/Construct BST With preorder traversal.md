### __Construct BST With preorder traversal__

- [Leetcode Question Link](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/)

__Solution 1: Brute force TC=O(n^2), SC=O(n)__

```md
Construct a BST from given pre-order traversal
for example if the given traversal is {10, 5, 1, 7, 40, 50},
then the output should be the root of the following tree.
     10
   /   \
  5     40
 /  \      \
1    7      50
```
```cpp

 
TreeNode* find(TreeNode* root,int cur)
{
   
    if(root==NULL) return new TreeNode(cur);
    else if(root->val>=cur) root->left=find(root->left,cur);
    else root->right=find(root->right,cur);
    return root;
}

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=NULL;
        for(int i=0;i<preorder.size();i++)
        root=find(root,preorder[i]);
        return root;
            
    }
};

```
