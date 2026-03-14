// Problem: Insert Node at Beginning of Linked List
// Approach:
// Create a new node and make its next pointer point to the current head.
// Then update the head to the new node.
//
// Time Complexity: O(1)
// Space Complexity: O(1)
// Problem: Delete Node from Beginning of Linked List
// Approach:
// Move the head pointer to the next node and delete the old head.
//
// Time Complexity: O(1)
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
    int arr[7]={2,4,6,7,8,9,10};
    node *head=NULL;
    //insert at first
    for(int i=0;i<7;i++){
        if(head==NULL){
            head=new node(arr[i]);
        }else{
            node *temp=new node(arr[i]);
            temp->next=head;
            head=temp;
        }
    }
    //traverse the list
    node *tail=head;
    while (tail!=NULL)
    {
       cout<<tail->data<<endl;
       tail=tail->next;
        
    }
   //delete from first
   tail=head;
   head=head->next;
   delete tail;
   tail=head;
   cout<<"after deletion"<<endl;
   while (tail!=NULL)
   {
    /* code */
    cout<<tail->data<<endl;
    tail=tail->next;
   }
   
}
