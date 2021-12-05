### __Recover Binary Search Tree__

```md
You are given the root of a binary search tree (BST), where the values of exactly
two nodes of the tree were swapped by mistake. Recover the tree without changing
its structure.
```
![image](https://user-images.githubusercontent.com/51910127/144742377-ca75036d-7c96-4a00-bbbc-43d3f60bb9d6.png)
![image](https://user-images.githubusercontent.com/51910127/144742387-081549b1-e35f-400b-9d3b-0eeaaeae93d3.png)
![image](https://user-images.githubusercontent.com/51910127/144742407-fcda5870-feb2-4857-b81a-d0eafea53f82.png)

### Solution 1: Inorder traversal based , TC= O(n+n+nlogn), SC=O(n)

- [Video link](https://www.youtube.com/watch?v=ZWGW7FminDM&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=53)
```
- Do a inorder traversal(or any traversal) and save the element in vector
- sort the vector 
- now do a inorder traversal and comapre the vector
- by putting one pointer in vector and current node in inorder traversal
```

### Solution 2: Inorder traversal based , TC= O(n), SC=O(1)

![image](https://user-images.githubusercontent.com/51910127/144742648-85a2b04f-7f9c-4c3c-9d2c-e44b781d813a.png)
![image](https://user-images.githubusercontent.com/51910127/144742661-b6a92544-94f3-4230-a182-02b9020d9468.png)


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
class Solution {
private: 
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last; 
private: 
    void inorder(TreeNode* root) {
        if(root == NULL) return; 
        
        inorder(root->left);
        
        if (prev != NULL && (root->val < prev->val))
        {
           
            // If this is first violation, mark these two nodes as
            // 'first' and 'middle'
            if ( first == NULL )
            {
                first = prev;
                middle = root;
            }
 
            // If this is second violation, mark this node as last
            else
                last = root;
        }
 
        // Mark this node as previous
        prev = root;
        inorder(root->right); 
    }
public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL; 
        prev = new TreeNode(INT_MIN); 
        inorder(root);
        if(first && last) swap(first->val, last->val); 
        else if(first && middle) swap(first->val, middle->val); 
    }
};

```
