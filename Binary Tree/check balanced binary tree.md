```py
'''class Node: 
    # Constructor to create a new Node 
    def __init__(self, data): 
        self.data = data 
        self.left = None
        self.right = None'''


#Function to check whether a binary tree is balanced or not.
class Solution:
    
    def isBalancedutil(self,root):
        if root is None:
            return 0
        
        left = self.isBalancedutil(root.left)
        if left is -1:
            return -1
        right = self.isBalancedutil(root.right)
        if right is -1:
            return -1
            
        if (abs(left-right) > 1) :
            return -1
        else:
            return max(left,right)+1

    def isBalanced(self,root):
        x= self.isBalancedutil(root)
        if x == -1:
            return 0
        else :
            return 1
```
