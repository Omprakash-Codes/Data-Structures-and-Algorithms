// Problem: Subtract Two Linked Lists
// Approach: Reverse + Subtraction with Borrow
// Description:
// Given two linked lists representing numbers, subtract the smaller number from the larger one.
//
// Steps:
// 1. Determine which number is larger.
// 2. Reverse both lists.
// 3. Perform subtraction digit by digit with borrow.
// 4. Reverse the result.
// 5. Remove leading zeros.
// Time Complexity: O(N)
// Space Complexity: O(1)
struct Node {
    int data;
     Node* next;
    Node(int d) : data(d), next(nullptr) {}
 };
Node* reverse(Node* head){
    Node* curr=head,*future,*prev=NULL;
    while(curr){
        future=curr->next;
        curr->next=prev;
        prev=curr;
        curr=future;
    }
    return prev;
}
int countlen(Node* head){
    int len=0;
    while(head){
        len++;
        head=head->next;
    }
    return len;
}
int isBigger(Node* head1,Node* head2){
    int len1=countlen(head1);
    int len2=countlen(head2);
    if(len1>len2){
        return 1;
    }else if(len2>len1){
        return 2;
    }else{
        while(head1){
         if(head1->data>head2->data){
            return 1;
         }else if(head2->data>head1->data){
            return 2;
         }
           head1=head1->next;
           head2=head2->next; 
        }
    }
    return 0;
}
Node* removeZero(Node* head){
    while(head && head->data==0){
        Node* temp=head;
        head=head->next;
        delete temp;
    }
    return head;
}
Node* subtractLinkedLists(Node* l1, Node* l2) {
    //function for remove trailing zeroes from start
    l1=removeZero(l1);
    l2=removeZero(l2);
    //function for check who is big number
    int Bigres=isBigger(l1,l2);
    if(Bigres==2){
        swap(l1,l2);
    }else if(Bigres==0){
        return new Node(0);
    }
    //l1 is bigger so we can perform the subtraction
    l1=reverse(l1);
    l2=reverse(l2);
    int borrow=0;
    Node* result=NULL;
    while(l1){
        int val1=l1->data;
        int val2=l2 ? l2->data:0;
        int difference=val1-val2-borrow;
        if(difference<0){
            borrow=1;
            difference+=10;
        }else{
            borrow=0;
        }
        Node* temp=new Node(difference);
        temp->next=result;
        result=temp;
        l1=l1->next;
        if(l2){
         l2=l2->next;
        }
    }
    //remove the trailing zero from the result
    return removeZero(result);
}
