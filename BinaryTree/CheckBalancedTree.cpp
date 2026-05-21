// Problem: Check if Binary Tree is Height Balanced
// Approach: Optimized Recursion
// Description:
// A binary tree is balanced if:
// difference between left subtree height
// and right subtree height is not more than 1
// for every node.
// Time Complexity: O(N)
// Space Complexity: O(H)
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};


class Solution {
public:
    int checkbal(Node* root){
        if(!root){
            return 0;
        }
        if(!root->left&&!root->right){
            return 1;
        }
        int leftheight=checkbal(root->left);
        if(leftheight==-1){
            return -1;
        }
        int rightheight=checkbal(root->right);
        if(rightheight==-1){
            return -1;
        }
        if(abs(leftheight-rightheight)>1){
            return -1;
        }
        return 1+max(leftheight,rightheight);
    }
    // Function to check if a binary tree is balanced or not.
    bool isBalanced(Node* root) {
        // code here
        return checkbal(root)!=-1;
    }
};
