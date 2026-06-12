// Problem: Convert Sorted Linked List to Binary Search Tree
// Approach: Divide And Conquer
// Description:
// Convert a sorted singly linked list
// into a height-balanced BST.
// Time Complexity: O(N log N)
// Space Complexity: O(log N)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 
class Solution {
public:
    int count(ListNode* head){
        int total=0;
        while(head){
            total++;
            head=head->next;
        }
        return total;
    }
    TreeNode* buildBst(ListNode* &head,int n){
        if(n==0){
            return NULL;
        }
        if(n==1){
            TreeNode* temp=new TreeNode(head->val);
            head=head->next;
            return temp;
        }
        TreeNode* left=buildBst(head,n/2);
        TreeNode* root=new TreeNode(head->val);
        root->left=left;
        head=head->next;
        root->right=buildBst(head,n-n/2-1);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        // Your code here
        int n=count(head);
        return buildBst(head,n);

    }
};
