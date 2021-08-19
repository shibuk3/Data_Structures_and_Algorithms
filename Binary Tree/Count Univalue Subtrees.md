[Problem Link](https://www.lintcode.com/en/old/problem/count-univalue-subtrees/) 

__This problem also known as Universal Value tree problem__
[Video link, asked in google, Facebook](https://www.youtube.com/watch?v=7HgsS8bRvjo)

Given a binary tree, count the number of uni-value subtrees.
A Uni-value subtree means all nodes of the subtree have the same value.

![image](https://user-images.githubusercontent.com/51910127/130019850-e410fe2a-37a7-48f0-93e2-84600067420f.png)

```cpp
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
bool count(TreeNode * root, int & a )

{    if(root->left==NULL &&root->right==NULL) {a++;return true;} 
    
      else if(root->left &&!root->right && count(root->left,a)&&root->left->val==root->val)
       { a++;return true;}
       else if(!root->left &&root->right && count(root->right,a)&&root->right->val==root->val)
        {a++;return true;}
       else if(root->left &&root->right )
      { 
         bool x=count(root->left,a);
         bool y=count(root->right,a);
        if( x&&y&& root->right->val==root->left->val && root->right->val==root->val  )
            {a++; return true;}
         
        //Can you guess why i have not included
        //count(root->left,a) and count(root->right,a)
       //in the same above if() condition ??
        
        
         
      }
        return false ;


}


class Solution {
public:
    /**
     * @param root: the given tree
     * @return: the number of uni-value subtrees.
     */
    int countUnivalSubtrees(TreeNode * root) {
      if(!root) return 0;
     //if(root->left==NULL &&root->right==NULL) {return 1;}
       int a=0;
       count(root,a);
       return a;  
        // write your code here
    }
};

```
