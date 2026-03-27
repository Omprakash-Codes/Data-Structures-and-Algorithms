// Problem: Clone a Linked List with Next and Random Pointer
// Approach: Optimal (Without Extra Space)
// Description:
// Each node has two pointers:
// 1. next   -> next node
// 2. random -> any node in list or NULL
//
// Steps:
// 1. Insert cloned nodes in between original nodes.
// 2. Assign random pointers for cloned nodes.
// 3. Separate the original and cloned list.
// Time Complexity: O(N)
// Space Complexity: O(1)
struct Node {
    int data;
    Node *next;
    Node *random;
    Node(int x) : data(x), next(nullptr), random(nullptr) {}
}; 

Node* cloneLinkedList(Node* head) {
    //make copy of the list and insert them in between the original list
      Node* curr=head;
      while(curr){
        Node* temp=new Node(curr->data);
        temp->next=curr->next;
        curr->next=temp;
        curr=temp->next;
      }
    //connet the random pointer of clone list using original list
     curr=head;
     while(curr){
        if(curr->random){
          curr->next->random=curr->random->next;
        }  
        curr=curr->next->next;
     }
    //dettached the clone list from original list
    curr=head;
    Node* result=head->next,*temp=head->next;
    while(curr){
        curr->next=temp->next;
        curr=temp->next;
        if(curr){
            temp->next=curr->next;
            temp=curr->next;
        }
    }
    return result;
}
