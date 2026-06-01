// Problem: Find Kth Smallest Element in BST
// Approach: Inorder Traversal
// Description:
// Find the kth smallest element in a BST.
// BST Property:
// Inorder traversal of BST gives
// elements in sorted order.
// Time Complexity: O(N)
// Space Complexity: O(H)
 * Definition for a binary tree node.
 * struct Node {
 *     int data;
 *     Node *left;
 *     Node *right;
 *     Node(int x) : data(x), left(NULL), right(NULL) {}
 * };


class Solution {
public:
    void find(Node* root,int&k,int&result){
        if(!root||k<0){
            return;
        }
        find(root->left,k,result);
        k--;
        if(k==0){
            result=root->data;
            return;
        }
        find(root->right,k,result);
    }
    int kthSmallest(Node* root, int k) {
        // Your code here
      int result;
      find(root,k,result);
      return result;
    }
};
