// Problem: Check if a Binary Tree is a BST
// Approach: Range Validation
// Description:
// Verify whether a binary tree satisfies
// BST properties.
// BST Property:
// Left Subtree  < Root
// Right Subtree > Root
// Time Complexity: O(N)
// Space Complexity: O(H)
* Definition for a binary tree node.
* struct Node {
    * int data;
    * Node *left;
    * Node *right;
    * Node(int x) : data(x), left(NULL), right(NULL) {}
    * };

    class Solution {
        public:
        bool checkBST(Node* root,int minval,int maxval){
            if(!root){
                return 1;
            }
            if(root->data<=minval || root->data>=maxval){
                return 0;
            }
           return checkBST(root->left,minval,root->data)&&checkBST(root->right,root->data,maxval);
        }
        bool isBST(Node* root) {
            // Your code here
           return checkBST(root,INT_MIN,INT_MAX);
        }
    };
