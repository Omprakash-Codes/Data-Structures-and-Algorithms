// Problem: Insert Node at End of Linked List
// Approach:
// Traverse the linked list until we reach the last node.
// Create a new node and attach it to the end of the list.
//
// Time Complexity: O(N)
// Space Complexity: O(1)
// Problem: Delete Node from End of Linked List
// Approach:
// Traverse the list to find the second last node.
// Remove the last node and update the next pointer.
//
// Time Complexity: O(N)
// Space Complexity: O(1)
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next=NULL;
    node(int val){
        data=val;
    }

};
int main(){
    int arr[6]={8,9,4,7,10,11};
    node *head=NULL;
    node *curr=NULL;
    //insert in the last position
    for(int i=0;i<6;i++){
    if(head==NULL){
    head=new node(arr[i]);
    curr=head;
    }else{
     node *temp=new node(arr[i]);
     curr->next=temp;
     curr=curr->next;
    }
   }
   //print/traverse the linked-list
   curr=head;
   while (curr!=NULL)
   {
      cout<<curr->data<<endl;
      curr=curr->next;
   }
   //delete karna hai last se
   node *prev=NULL;
   curr=head;
   while (curr->next!=NULL)
   {
        prev=curr;
        curr=curr->next;
   }
   prev->next=NULL;
   delete curr;
   //print/traverse the linked-list
   curr=head;
   cout<<"after deletion"<<endl;
   while (curr!=NULL)
   {
      cout<<curr->data<<endl;
      curr=curr->next;
   }

}

