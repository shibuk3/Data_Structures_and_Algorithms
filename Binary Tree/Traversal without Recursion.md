### __Inorder Traversal without Recursion__
```md
            1
          /   \
        2      3
      /  \
    4     5
```
```cpp
// C++ program to print inorder traversal
// using stack.
#include<bits/stdc++.h>
using namespace std;
 
/* A binary tree Node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    Node (int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
 
/* Iterative function for inorder tree
   traversal */
void inOrder(struct Node *root)
{
    stack<Node *> s;
    Node *curr = root;
 
    while (curr != NULL || s.empty() == false)
    {
        /* Reach the left most Node of the
           curr Node */
        while (curr !=  NULL)
        {
            /* place pointer to a tree node on
               the stack before traversing
              the node's left subtree */
            s.push(curr);
            curr = curr->left;
        }
 
        /* Current must be NULL at this point */
        curr = s.top();
        s.pop();
 
        cout << curr->data << " ";
 
        /* we have visited the node and its
           left subtree.  Now, it's right
           subtree's turn */
        curr = curr->right;
 
    } /* end of while */
}
 
/* Driver program to test above functions*/
int main()
{
 
    /* Constructed binary tree is
              1
            /   \
          2      3
        /  \
      4     5
    */
    struct Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
 
    inOrder(root);
    return 0;
}
```
```md
Output: 

 4 2 5 1 3
Time Complexity: O(n)
Space Complexity: O(H)
H = Height of Binary Treea
```
### __Iterative Preorder Traversal without recursion__
```md
           10
          /   \
        8      2
      /  \    /
    3     5  2

```

```cpp
#include <bits/stdc++.h>
using namespace std;
 
// Tree Node
struct Node {
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
 
// Iterative function to do Preorder traversal of the tree
void preorderIterative(Node* root)
{
    if (root == NULL)
        return;
 
    stack<Node*> st;
 
    // start from root node (set current node to root node)
    Node* curr = root;
 
    // run till stack is not empty or current is
    // not NULL
    while (!st.empty() || curr != NULL) {
        // Print left children while exist
        // and keep pushing right into the
        // stack.
        while (curr != NULL) {
            cout << curr->data << " ";
 
            if (curr->right)
                st.push(curr->right);
 
            curr = curr->left;
        }
 
        // We reach when curr is NULL, so We
        // take out a right child from stack
        if (st.empty() == false) {
            curr = st.top();
            st.pop();
        }
    }
}
 
// Driver Code
int main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->left->left = new Node(70);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->left->left->right = new Node(80);
 
    preorderIterative(root);
 
    return 0;
}

```
```
Output: 
10 20 40 70 80 50 30 60
 

Time Complexity: O(N) 
Auxiliary Space: O(H), where H is the height of the tree.
```
### __Method 1: Iterative Postorder Traversal without recursion and using 2 stack__

- [VIDEO Link](https://www.youtube.com/watch?v=2YBhNLodD8Q)

```md
iterative postorder traversal is discussed, which is more complex
than the other two traversals (due to its nature of non-tail recursion,
there is an extra statement after the final recursive call to itself)
```
![image](https://user-images.githubusercontent.com/51910127/144710137-52f757cd-549c-4967-88ef-abcecc3402a6.png)

```cpp
void postOrderIterative(Node* root)
{
    if (root == NULL)
        return;
 
    // Create two stacks
    stack<Node *> s1, s2;
 
    // push root to first stack
    s1.push(root);
    Node* node;
 
    // Run while first stack is not empty
    while (!s1.empty()) {
        // Pop an item from s1 and push it to s2
        node = s1.top();
        s1.pop();
        s2.push(node);
 
        // Push left and right children
        // of removed item to s1
        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }
 
    // Print all elements of second stack
    while (!s2.empty()) {
        node = s2.top();
        s2.pop();
        cout << node->data << " ";
    }
}
```
