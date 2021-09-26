###  __Print the longest path from root to leaf in a Binary tree__

```cpp
vector<int> longestPath(Node* root)
{
 
    // If root is null means there
    // is no binary tree so
    // return a empty vector
    if (root == NULL) {
        vector<int> temp
            = {};
        return temp;
    }
 
    // Recursive call on root->right
    vector<int> rightvect
        = longestPath(root->right);
 
    // Recursive call on root->left
    vector<int> leftvect
        = longestPath(root->left);
 
    // Compare the size of the two vectors
    // and insert current node accordingly
    if (leftvect.size() > rightvect.size())
        leftvect.push_back(root->data);
 
    else
        rightvect.push_back(root->data);
 
    // Return the appropriate vector
    return (leftvect.size() > rightvect.size()
                ? leftvect
                : rightvect);
}
```
