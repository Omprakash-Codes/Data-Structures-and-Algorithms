// Problem: Check Whether BST Contains a Dead End
// Approach: Recursion with Range Tracking
// Description:
// Determine if a BST contains a dead end.
// A dead end is a leaf node such that
// no further node can be inserted while
// maintaining BST properties.
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
#include<climits>
class Solution {
public:
    bool isdead(Node* root,int minval,int maxval){
        if(!root){
            return 0;
        }
        if(!root->left && !root->right){
            if(root->data+1==maxval && root->data-1==minval){
                return 1;
            }
        }
        return isdead(root->left,minval,root->data) || isdead(root->right,root->data,maxval);
    }
    bool isDeadEnd(Node *root) {
        // Your code here
        return isdead(root,0,INT_MAX);
    }
};
