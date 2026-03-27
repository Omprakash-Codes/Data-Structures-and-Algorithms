// Problem: Intersection of Two Linked Lists
// Approach: Two Pointer(slow and fast) Technique
// Description:
// first we make loop in the list so we can use floyd's algorithm.
// When slow and fast pointer meat, move slow to head of o list.
// If lists intersect, both pointers will meet at intersection point.
// Time Complexity: O(N + M)
// Space Complexity: O(1)
 struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
}; 

Node* intersectPoint(Node* head1, Node* head2) {
    //make loop in the list
    Node* curr=head1;
    while(curr->next){
        curr=curr->next;
    }
    curr->next=head2;
    //now find the where is loop and start/intersection point
    Node* slow=head1,*fast=head1;
    while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            break;
        }
    }
    slow=head1;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}
