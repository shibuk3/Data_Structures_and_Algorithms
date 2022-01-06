### __Maximum sum path from leaf to leaf__

```cpp
int maxsum(node* root, int* ans)
{
     if(root==NULL) return 0;
     int l= find(root->left,ans);
     int r= find(root->right,ans);
     
     if(root->left&&root->right)
     { return *ans= max(l+r+root->data,*ans);}
     
     return max(l,r)+root->data;

}

int find(node* root)
{
   int x=INT_MIN;
   maxsum(root,&x);
   return x;
}

```
https://www.youtube.com/watch?v=FxgpgxH2k8o
https://www.codingninjas.com/codestudio/problems/maximum-path-sum-between-two-leaves_794950
