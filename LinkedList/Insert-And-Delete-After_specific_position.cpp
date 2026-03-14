// Problem: Insert Node After a Specific Position in Linked List
// Approach:
// Traverse the linked list until we reach the given position.
// Create a new node and update pointers to insert it after that position.
//
// Time Complexity: O(N)
// Space Complexity: O(1)
// Problem: Delete Node After a Specific Position in Linked List
// Approach:
// Traverse the linked list until the given position.
// Remove the node after that position by updating the pointers.
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
   //insert data after 7
   curr=head;
   while (curr->data!=7)
   {
      curr=curr->next;
   }
   node *temp=new node(6);
   temp->next=curr->next;
   curr->next=temp;
   //print/traverse the linked-list
   curr=head;
   cout<<"after insertion"<<endl;
   while (curr!=NULL)
   {
      cout<<curr->data<<endl;
      curr=curr->next;
   }
   //delete after 7
   curr=head;
   node *del=head;
   while (curr->data!=7)
   {
     curr=curr->next;
      del=curr->next;
   }
   del=curr->next;
   curr->next=del->next;
   delete del;
   //print/traverse the linked-list
   curr=head;
   cout<<"after deletion"<<endl;
   while (curr!=NULL)
   {
      cout<<curr->data<<endl;
      curr=curr->next;
   }
   
}
