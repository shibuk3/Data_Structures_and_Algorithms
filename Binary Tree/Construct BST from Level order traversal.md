### __Construct BST from Level order traversal__

```md
Input : arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10}
Output : BST: 
        7        
       / \       
      4   12      
     / \  /     
    3  6 8    
   /  /   \
  1   5   10
  
 The idea is to use the Recursion:- 
We know that the first element will always be the root of tree and second element 
will be the left child and third element will be the right child (if fall in the range),
and so on for all the remaining elements.
1) First pick the first element of the array and make it root. 
2) Pick the second element, if it’s value is smaller than root node value make it left child, 
3) Else make it right child 
4) Now recursively call the step (2) and step (3) to make a BST from its level Order Traversal.
Below is the implementation of above approach: 
  
```
```cpp
// C++ implementation to construct a BST
// from its level order traversal
#include <bits/stdc++.h>
 
using namespace std;
 
 
// node of a BST
struct Node
{
    int data;
    Node *left, *right;
};
 
 
// function to get a new node
Node* getNode(int data)
{
    // Allocate memory
    Node *newNode =
        (Node*)malloc(sizeof(Node));
     
    // put in the data   
    newNode->data = data;
    newNode->left = newNode->right = NULL;   
    return newNode;
}
 
 
// function to construct a BST from
// its level order traversal
Node *LevelOrder(Node *root , int data)
{
     if(root==NULL){   
        root = getNode(data);
        return root;
     }
     if(data <= root->data)
     root->left = LevelOrder(root->left, data);
     else
     root->right = LevelOrder(root->right, data);
     return root;    
}
 
Node* constructBst(int arr[], int n)
{
    if(n==0)return NULL;
    Node *root =NULL;
 
    for(int i=0;i<n;i++)
    root = LevelOrder(root , arr[i]);
     
    return root;
}
 
// function to print the inorder traversal
void inorderTraversal(Node* root)
{
    if (!root)
        return;
     
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);   
}
 
 
// Driver program to test above
int main()
{
    int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
     
    Node *root = constructBst(arr, n);
     
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    return 0;   
}
```
```md
Inorder Traversal: 1 3 4 5 6 7 8 10 12
Time Complexity : O(n^2) 
This is because the above program is like we are inserting n
nodes in a bst which takes O(n2) time in the worst case.
```
### __2nd Method:   TC=O(N)__

```md
The idea is to make a struct element NodeDetails which contains
a pointer to the node, minimum data and maximum data of the ancestor. Now perform the steps as follows: 

- Push the root node to the queue of type NodeDetails.
- Extract NodeDetails of a node from the queue and compare them with the minimum and maximum values.
- Check whether there are more elements in the arr[] and arr[i] can be left child of ‘temp.ptr’ or not.
- Check whether there are more elements in the arr[] and arr[i] can be the right child of ‘temp.ptr’ or not.
- End the loop when the queue becomes empty.

Below is the implementation of the above approach:
```

```cpp
// C++ program to construct BST
// using level order traversal
#include <bits/stdc++.h>
using namespace std;
 
// Node structure of a binary tree
struct Node {
    int data;
    Node* right;
    Node* left;
 
    Node(int x)
    {
        data = x;
        right = NULL;
        left = NULL;
    }
};
 
// Structure formed to store the
// details of the ancestor
struct NodeDetails {
    Node* ptr;
    int min, max;
};
 
// Function for the preorder traversal
void preorderTraversal(Node* root)
{
    if (!root)
        return;
    cout << root->data << " ";
 
    // Traversing left child
    preorderTraversal(root->left);
 
    // Traversing right child
    preorderTraversal(root->right);
}
 
// Function to make a new node
// and return its pointer
Node* getNode(int data)
{
    Node* temp = new Node(0);
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
 
// Function to construct the BST
Node* constructBst(int arr[], int n)
{
    if (n == 0)
        return NULL;
 
    Node* root;
 
    queue<NodeDetails> q;
 
    // index variable to
    // access array elements
    int i = 0;
 
    // Node details for the
    // root of the BST
    NodeDetails newNode;
    newNode.ptr = getNode(arr[i++]);
    newNode.min = INT_MIN;
    newNode.max = INT_MAX;
    q.push(newNode);
 
    // Getting the root of the BST
    root = newNode.ptr;
 
    // Until there are no more
    // elements in arr[]
    while (i != n) {
 
        // Extracting NodeDetails of a
        // node from the queue
        NodeDetails temp = q.front();
        q.pop();
 
        // Check whether there are more elements
        // in the arr[] and arr[i] can be
        // left child of 'temp.ptr' or not
        if (i < n
            && (arr[i] < temp.ptr->data
                && arr[i] > temp.min)) {
 
            // Create NodeDetails for newNode
            // and add it to the queue
            newNode.ptr = getNode(arr[i++]);
            newNode.min = temp.min;
            newNode.max = temp.ptr->data;
            q.push(newNode);
 
            // Make this 'newNode' as left child
            // of 'temp.ptr'
            temp.ptr->left = newNode.ptr;
        }
 
        // Check whether there are more elements
        // in the arr[] and arr[i] can be
        // right child of 'temp.ptr' or not
        if (i < n
            && (arr[i] > temp.ptr->data
                && arr[i] < temp.max)) {
 
            // Create NodeDetails for newNode
            // and add it to the queue
            newNode.ptr = getNode(arr[i++]);
            newNode.min = temp.ptr->data;
            newNode.max = temp.max;
            q.push(newNode);
 
            // Make this 'newNode' as right
            // child of 'temp.ptr'
            temp.ptr->right = newNode.ptr;
        }
    }
 
    // Root of the required BST
    return root;
}
 
// Driver code
int main()
{
    int n = 9;
 
    int arr[n] = { 7, 4, 12, 3, 6, 8, 1, 5, 10 };
     
    // Function Call
    Node* root = constructBst(arr, n);
 
    preorderTraversal(root);
 
    return 0;
}

```

```md
Output:

7 4 3 1 6 5 12 8 10
```
