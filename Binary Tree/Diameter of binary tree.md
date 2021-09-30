```cpp
 */
int diameterOpt(struct TreeNode* root, int* height, int& ans)
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
    ldiameter = diameterOpt(root->left, &lh,ans);
    rdiameter = diameterOpt(root->right, &rh,ans);
  
    // Height of current node is max of heights of left and
    // right subtrees plus 1ode 
    *height = max(lh, rh) + 1;
  
    return ans = max(ans,lh+rh+1); // update the answer, because diameter of a
    // tree is nothing but maximum value of
    // (left_height + right_height + 1) for each node
}

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int i=0; int ans=0;
        return diameterOpt(root,&i,ans)-1;
    }
};
```
