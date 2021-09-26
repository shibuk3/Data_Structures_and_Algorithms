### __Diameter of Binary Tree__

[Problem Link]()

![image](https://user-images.githubusercontent.com/51910127/134819342-926ead36-dc2f-4838-88c7-ccddd8adba6b.png)
![image](https://user-images.githubusercontent.com/51910127/134819355-c36d054b-148f-4df3-a474-a2e02630b35e.png)



- 1st Solution : TC= O(n^2)
```
int height(struct node* node);
 
// Function to get diameter of a binary tree
int diameter(struct node* tree)
{
    // base case where tree is empty
    if (tree == NULL)
        return 0;
 
    // get the height of left and right sub-trees
    int lheight = height(tree->left);
    int rheight = height(tree->right);
 
    // get the diameter of left and right sub-trees
    int ldiameter = diameter(tree->left);
    int rdiameter = diameter(tree->right);
 
    // Return max of following three
    // 1) Diameter of left subtree
    // 2) Diameter of right subtree
    // 3) Height of left subtree + height of right subtree + 1
    return max(lheight + rheight + 1,
            max(ldiameter, rdiameter));
}
 
// UTILITY FUNCTIONS TO TEST diameter() FUNCTION
 
// The function Compute the "height" of a tree. Height is
// the number f nodes along the longest path from the root
// node down to the farthest leaf node.
int height(struct node* node)
{
    // base case tree is empty
    if (node == NULL)
        return 0;
 
    // If tree is not empty then height = 1 + max of left
    // height and right heights
    return 1 + max(height(node->left), height(node->right));
}
```

- 2nd Solution: TC=O(n)

```
int diameterOpt(struct TreeNode* root, int* height)
{
    // lh --> Height of left subtree
    // rh --> Height of right subtree
    int lh = 0, rh = 0;
  
    // ldiameter  --> diameter of left subtree
    // rdiameter  --> Diameter of right subtree
    int ldiameter = 0, rdiameter = 0;
  
    if (root == NULL) {
        *height = 0;
        return 0; // diameter is also 0
    }
  
    // Get the heights of left and right subtrees in lh and
    // rh And store the returned values in ldiameter and
    // ldiameter
    ldiameter = diameterOpt(root->left, &lh);
    rdiameter = diameterOpt(root->right, &rh);
  
    // Height of current node is max of heights of left and
    // right subtrees plus 1
    *height = max(lh, rh) + 1;
  
    return max(lh + rh + 1, max(ldiameter, rdiameter));
}

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int i=0;
        return diameterOpt(root,&i)-1;
    }
};
```
