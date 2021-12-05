### __Binary Tree Consrtruction Theory from Traversal__

## __Can we construct Binary Tree from inorder or preorder or postorder (1 traversal only)?__

```md
Yes, we can construct a Binary Tree from one traversal only (Inorder or Postorder or Preorder) but
we cannot construct an unique Binary Tree from a single traversal (inorder or preorder or postorder).
This is because from a given traversal, we do not have the complete information. We have the following information:

Inorder -> We know the leftmost and rightmost node in Binary Tree
Preorder -> We know the root node of the Binary Tree for sure
Postorder -> We know the root node of the Binary Tree for sure
The three traversal in summary:

Inorder: left, root, right
Preorder: root, left, right
Postorder: left, right, root
The problem is as follows


Problem with Inorder
With Inorder traversal, we know the leftmost and rightmost node in the Binary Tree but we do
not know the root of the Binary Tree.
Hence, any node (including the leftmost or the rightmost node) can be the root of the Binary Tree.

If we consider the leftmost node as the root node, then we get a right skewed Binary Tree.
If we consider the rightmost node as the root node, then we get a left skewed Binary Tree.
The problem exists from every subtree of the Binary Tree. We have no information about the root node.


Problem with Preorder
With Preorder traversal, we know the root of the Binary Tree for sure but we do not know
the leftmost or rightmost node of the Binary Tree.

Consider the case when we can have no right sub-tree from the root. Then, the traversal will

go into the leftsubtree directly and the last node will be in the left sub-tree and is not the rightmost node.
Therefore, we cannot create a unique Binary Tree using Preorder.


Problem with Postorder
With Postorder traversal, we know the root of the Binary Tree for sure but we do not
know the leftmost or rightmost node of the Binary Tree.

Consider the case when we can have no left sub-tree from the root. Then, the traversal
will go into the right sub-tree directly and the first node will be in the right sub-tree
and is not the leftmost node.


 
Therefore, we cannot create a unique Binary Tree using Postorder.

Which combinations will work?
To construct a unique Binary Tree, we need to know the exact nodes that are:

Root
Leftmost node
Rightmost node
Preorder and Postorder traversal give us information about the root node.
Inorder traversal give us information about the leftmost and rightmost node.

Hence, if we take any two traversals: one being Inorder and the order from Preorder
or Postorder, we can create a unique Binary Tree.
Note: We cannot create a Unique Binary Tree from the combination of Preorder and Postorder
traversal as we have the information of the root only.


 
Hence, combinations from which we can create a unique Binary Tree are:

Inorder + Postorder
Inorder + Preorder
Combinations from which we cannot create a unique Binary Tree are:

Inorder
Postorder
Preorder
Preorder + Postorder
This gives you a good idea of whether it is possible to construct a Binary Tree from
a given traversal like Inorder or Postorder or Preorder.
```
### __What about Bst ? can we construct BST with only single traversal ??

```md
BST can be constructed with any traversal
- inorder only
- postorder only
- preorder only
- level order traversal only
```
