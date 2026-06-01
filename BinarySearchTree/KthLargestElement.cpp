// Problem: Find Kth Largest Element in BST
// Approach: Reverse Inorder Traversal
// Description:
// Find the kth largest element in a BST.
// BST Property:
// Reverse Inorder Traversal of BST gives
// elements in descending order.
// Time Complexity
 * Definition for a binary tree node.
 * struct Node {
 *     int data;
 *     Node *left;
 *     Node *right;
 *     Node(int x) : data(x), left(NULL), right(NULL) {}
 * };

class Solution {
public:
    void find(Node* root,int&k,int&ans){
        if(!root||k<0){
            return;
        }
        find(root->right,k,ans);
        k--;
        if(k==0){
            ans=root->data;
            return;
        }
        find(root->left,k,ans);
    }
    int kthLargest(Node* root, int k) {
        // Your code here
        int ans;
        find(root,k,ans);
        return ans;
    }
};
