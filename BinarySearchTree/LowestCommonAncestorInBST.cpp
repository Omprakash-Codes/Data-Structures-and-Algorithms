// Problem: Lowest Common Ancestor in a BST
// Approach: BST Property
// Description:
// Find the Lowest Common Ancestor (LCA)
// of two given nodes in a Binary Search Tree.
// Time Complexity: O(H)
// Space Complexity: O(H)
/**
 * Definition for a binary tree node.
 * struct Node {
 *     int data;
 *     Node *left;
 *     Node *right;
 *     Node(int x) : data(x), left(NULL), right(NULL) {}
 * };

class Solution {
public:
    Node* LCA(Node* root, int n1, int n2) {
        // Your code here
        if(!root){
            return NULL;
        }
        while(root){
            if(n1>root->data && n2>root->data){
                root=root->right;
            }else if(n1<root->data && n2<root->data){
                root=root->left;
            }else{
                return root;
            }
        }
        return NULL;
    }
};
