// Problem: Remove nodes which have a greater value on right side
// Approach: Recursion + Backtraking
// Description:
// 1. go to the last node of the list
// 2. then backtrack and compare the val if current val is less than curr-next-val the delete
// Time Complexity: O(N)
// Space Complexity: O(N)
// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
ListNode* removenodes(ListNode* head ){
	//base case
	if(head==NULL || head->next==NULL){
		return head;
	}
	//go to last node 
	head->next=removenodes(head->next);
	if(head->val < head->next->val){
		ListNode *temp=head->next;
		delete head;
		return temp;
	}
	return head;
}

ListNode* removeNodes(ListNode* head) {
    return removenodes(head);
}
