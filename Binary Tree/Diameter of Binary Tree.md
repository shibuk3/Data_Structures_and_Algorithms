### __Diameter of Binary Tree__

[Problem Link]()

![image](https://user-images.githubusercontent.com/51910127/134819342-926ead36-dc2f-4838-88c7-ccddd8adba6b.png)
![image](https://user-images.githubusercontent.com/51910127/134819355-c36d054b-148f-4df3-a474-a2e02630b35e.png)



- 1st Solution : TC= O(n^2)
```cpp
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

### third solution easy to grab

```cpp
int find(TreeNode* root, int* ans)
{
    if(!root) return  0;
    
    
    
    int l= find(root->left,ans);
    int r= find(root->right,ans);
    
    *ans=max(*ans,l+r+1);
    return max(l,r)+1;
    
    
    
}
class Solution {
public:
    
    int diameterOfBinaryTree(TreeNode* root) {
        int x=0;
         find(root,&x);
            
           return x;
    }
};
```

 


- 2nd Solution: TC=O(n)

```cpp
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
```py
# Python3 program to find the diameter of a binary tree
# A binary tree Node


class Node:

	# Constructor to create a new Node
	def __init__(self, data):
		self.data = data
		self.left = self.right = None

# utility class to pass height object


class Height:
	def __init(self):
		self.h = 0

# Optimised recursive function to find diameter
# of binary tree


def diameterOpt(root, height):

	# to store height of left and right subtree
	lh = Height()
	rh = Height()

	# base condition- when binary tree is empty
	if root is None:
		height.h = 0
		return 0

	# ldiameter --> diameter of left subtree
	# rdiameter --> diameter of right subtree

	# height of left subtree and right subtree is obtained from lh and rh
	# and returned value of function is stored in ldiameter and rdiameter

	ldiameter = diameterOpt(root.left, lh)
	rdiameter = diameterOpt(root.right, rh)

	# height of tree will be max of left subtree
	# height and right subtree height plus1

	height.h = max(lh.h, rh.h) + 1

	# return maximum of the following
	# 1)left diameter
	# 2)right diameter
	# 3)left height + right height + 1
	return max(lh.h + rh.h + 1, max(ldiameter, rdiameter))

# function to calculate diameter of binary tree


def diameter(root):
	height = Height()
	return diameterOpt(root, height)


# Driver Code
if __name__ == "__main__":
	root = Node(1)
	root.left = Node(2)
	root.right = Node(3)
	root.left.left = Node(4)
	root.left.right = Node(5)

	"""
Constructed binary tree is 
			1
		/ \
		2	 3
		/ \
	4	 5
"""

	print("The diameter of the binary tree is:", end=" ")
	# Function Call
	print(diameter(root))

# This code is contributed by Shweta Singh(shweta44)


```

```py

```
