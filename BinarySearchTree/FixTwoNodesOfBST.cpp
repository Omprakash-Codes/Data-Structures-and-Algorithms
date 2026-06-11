// Problem: Fixing Two Nodes of a BST
// Approach: Inorder Traversal
// Description:
// Two nodes of a BST are swapped by mistake.
// Restore the BST without changing its structure.
// Time Complexity: O(N)
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
    void checkfault(Node* root,Node* &prev,Node* &first,Node* &last){
        if(!root){
            return;
        }
        checkfault(root->left,prev,first,last);
        if(prev){
            if(prev->data>root->data){
                if(!first){
                    first=prev;
                    last=root;
                }else{
                    last=root;
                }
            }
        }
        prev=root;
        checkfault(root->right,prev,first,last);
    }
    void correctBST(struct Node *root) {
        // Your code here
        Node* prev=NULL,*first=NULL,*last=NULL;
        checkfault(root,prev,first,last);
        if(first){
         swap(first->data,last->data);
        } 
    }
};
