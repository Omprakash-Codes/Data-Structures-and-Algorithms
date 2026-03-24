// Problem: Merge K Sorted Linked Lists
// Approach: Divide and Conquer (Merge Sort Technique)
// Description:
// Instead of merging all lists at once, we divide the lists into two halves,
// recursively merge each half, and then merge the two sorted lists.
//
// Steps:
// 1. Divide the list of linked lists into two halves.
// 2. Recursively merge left half and right half.
// 3. Merge the two sorted lists.
//
// Time Complexity: O(N log K)
// Space Complexity: O(log K) recursion stack

 * Definition for singly-linked list.
  struct ListNode {
   int val;
       ListNode *next;
       ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

 //this function help to divide the array until they bacame single
 ListNode* MergeTwoList( ListNode* head1, ListNode* head2){
    if(!head1){
        return head2;
    }
    if(!head2){
        return head1;
    }
    //create dummy node for merge the list 
    ListNode* head=new ListNode(0);
    ListNode* tail=head;
    while(head1 && head2){
        if(head1->val<=head2->val){
            tail->next=head1;
            head1=head1->next;
            tail=tail->next;
            tail->next=NULL;
        }else{
            tail->next=head2;
            head2=head2->next;
            tail=tail->next;
            tail->next=NULL;
        }
    }
    if(head1){
        tail->next=head1;
    }else{
        tail->next=head2;
    }
    //remove the dummy node which is created in start
    ListNode* temp=head;
    head=head->next;
    delete temp;
    return head;
 }
 ListNode* Divide(vector<ListNode*>& lists,int start,int end){
    //base case
    if(start==end){
        return lists[start];
    }

    int mid=start+(end-start)/2;
    //divide first half part
   ListNode* head1=Divide(lists,start,mid);
    //divide next half part
   ListNode* head2=Divide(lists,mid+1,end);
   //this function is use for merge the two sorted list
   return MergeTwoList(head1,head2);
 }
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size()==0){
        return NULL;
    }
   return  Divide(lists,0,lists.size()-1);
}
