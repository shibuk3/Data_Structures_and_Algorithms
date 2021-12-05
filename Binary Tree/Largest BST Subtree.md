### __Largest BST Subtree, Solution 1: Brute Force TC=O(n^2), SC=O(1)__

- [Video explaination](https://www.youtube.com/watch?v=X0oXMdtUDwo&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=54)

```md
Go to each node and check its subtree that it is bst or not
```



![image](https://user-images.githubusercontent.com/51910127/144740493-8b091d8c-2cc6-4c00-b4c6-cbcfdfadc4ee.png)


### __Solution 2: O(n), SC(1), Follows postorder__
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class NodeValue {
public:
    int maxNode, minNode, maxSize;
    
    NodeValue(int minNode, int maxNode, int maxSize) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

class Solution {
private:
    NodeValue largestBSTSubtreeHelper(TreeNode* root) {
        // An empty tree is a BST of size 0.
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        
        // Get values from left and right subtree of current tree.
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);
        
        // Current node is greater than max in left AND smaller than min in right, it is a BST.
        if (left.maxNode < root->val && root->val < right.minNode) {
            // It is a BST.
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), 
                            left.maxSize + right.maxSize + 1);
        }
        
        // Otherwise, return [-inf, inf] so that parent can't be valid BST
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
    public:
    int largestBSTSubtree(TreeNode* root) {
        return largestBSTSubtreeHelper(root).maxSize;
    }
};
```
