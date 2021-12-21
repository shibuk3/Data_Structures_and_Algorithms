```cpp
#include<iostream>
#include<bits/stdc++.h>

Node* reverse(Node* head1)
  {  
      Node* temp=head1;
      if(!head1->next)
      {  
          return head1;}
      else
      {
            Node * save1= reverse(temp->next);
            Node *save2= temp->next->next;
            temp->next->next =temp;
            temp->next=save2;
          
          return save1;
      }
      
      
      
      
  }
 Node* create(int count )
 {   Node * head=NULL;
     Node*  prev= NULL;
   int x=0;   
  while(x<=count)
     {
           //cin>>x;
            Node* temp= new Node(0);
            x++;
            if(!head) head=temp;
            else{
            prev->next=temp;}
            prev=temp;
     }
     
     return head;
 }


Node *multiply(Node *head1, Node *head2,Node * ans)
{   Node* temp1=head1;Node* temp2=head2;
     Node* temp3= ans;   
    Node* after=ans;
 while(temp2)
    {
          temp1=head1; int carry=0;
        
        while(temp1)
        {
            int x= temp1->data*temp2->data+ans->data+carry;
            if(x>9) carry=x/10;
            
                ans->data=x%10;
            
            
            
            temp1=temp1->next;
            temp3=temp3->next;
        }
        if(!temp2->next)
        {temp3->next->data=-1; temp3->next->next=NULL;}
     temp3=after->next;
     
     after=after->next;
     temp2=temp2->next;
    }
 return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int x=INT_MIN;
        Node* head1=NULL;
        Node* prev1=NULL;
        int count1=0, count2=0;
        while(x!=-1)
        {
            cin>>x;
            Node* temp= new Node(x);
            count1++;
            if(!head1) head1=temp;
            else{
            prev1->next=temp;}
            prev1=temp;
        }
        x=INT_MIN;
        Node* head2=NULL;
        Node* prev2=NULL;
         while(x!=-1)
        {
            cin>>x;
            Node* temp= new Node(x);count2++;
            if(!head2) head2=temp;
            else{
            prev2->next=temp;}
            prev2=temp;
        }
        Node* ans= create(count1+count2);
        ans= multiply(head1, head2,ans);
        ans=reverse(ans);
        
       return ans; 
        
    }
    
    return 0;
}
```
