### __Reverse LInked list__

```cpp
#include <iostream>

using namespace std;
class node
{ public:
  int val;
  node* next;
    
    
};
 node* reverse(node* start)
 {  //cout<<start->val;
     if(start->next!=NULL)
     {
         node* temp= reverse(start->next);
         node* temp1=start->next;
         temp1->next=start;
         start->next=NULL;
         
     }
      else
        return start;
 }

int main()
{
    node* f=new node();
    f->val=1;
    node* g=new node();
    f->next=g;
    g->val=2;
    node* h=new node();
    g->next= h;
    h->val=3;
    node* i=new node();
    h->next=i;
    i->val=4;
    
    node* root=reverse(f);
    
    while(root)
    {cout<<root->val<<" ";
     root=root->next;
    }
    return 0;
}
```
