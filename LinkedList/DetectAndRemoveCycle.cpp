// Problem: Detect and Remove Cycle in Linked List
// Approach: Floyd’s Cycle Detection Algorithm
// Description:
// 1. Use slow and fast pointers to detect cycle.
// 2. If cycle exists, find the starting node of the cycle.
// 3. Traverse to the last node of cycle and break the link.
//
// Time Complexity: O(N)
// Space Complexity: O(1)
/* struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
}; */

void removeLoop(Node* head) {
    if(!head || !head->next){
        return;
    }
    Node* slow=head;
    Node* fast=head;
    // fist find the loop is exist in  list or not
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            break;
        }
    }
    //agar koi loop exist hi na kare then return 
    if(slow!=fast){
        return;
    }
    //find the point where loop is start
    slow=head;
    while(slow!=fast){
     slow=slow->next;
     fast=fast->next;
    }
    //remove the loop
    Node* temp=slow;
    while(temp->next!=slow){
        temp=temp->next;
    }
    temp->next=NULL;
    
}
