// Problem: Flatten a Linked List
// Approach: Merge (Divide & Conquer style)
// Description:
// Each node has two pointers:
// 1. next   -> points to next list
// 2. bottom -> points to sorted linked list
//
// Goal: Flatten all lists into a single sorted list using bottom pointers.
//
// Steps:
// 1. Recursively flatten the next list.
// 2. Merge current list with flattened next list.
//
// Time Complexity: O(N * M)
// Space Complexity: O(N) recursion stack
 struct Node {
    int data;
    struct Node * next;
    struct Node * bottom;
    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
}; 
 Node* MergeTwoList( Node* head1, Node* head2){
    if(!head1){
        return head2;
    }
    if(!head2){
        return head1;
    }
    //create dummy node for merge the list 
    Node* head=new Node(0);
    Node* tail=head;
    while(head1 && head2){
        if(head1->data<=head2->data){
            tail->bottom=head1;
            head1=head1->bottom;
            tail=tail->bottom;
            tail->bottom=NULL;
        }else{
            tail->bottom=head2;
            head2=head2->bottom;
            tail=tail->bottom;
            tail->bottom=NULL;
        }
    }
    if(head1){
        tail->bottom=head1;
    }else{
        tail->bottom=head2;
    }
    //remove the dummy node which is created in start
    Node* temp=head;
    head=head->bottom;
    delete temp;
    return head;
 }
 Node* Divide(vector<Node*>& lists,int start,int end){
    //base case
    if(start==end){
        return lists[start];
    }

    int mid=start+(end-start)/2;
    //divide first half part
   Node* head1=Divide(lists,start,mid);
    //divide next half part
   Node* head2=Divide(lists,mid+1,end);
   //this function is use for merge the two sorted list
   return MergeTwoList(head1,head2);
 }
Node* flatten(Node* root) {
    if(!root){
        return NULL;
    }
    // Your code here
    vector<Node*>list;
    Node* prev=NULL;
    while(root){
        list.push_back(root);
        prev=root;
        root=root->next;
        prev->next=NULL;
    }
    return Divide(list,0,list.size()-1);
}
