// Problem: Is Binary Tree Heap
// Approach:
// Complete Binary Tree + Max Heap Property
// Description:
// Determine whether a given binary tree is
// a valid Max Heap. A binary tree is a heap
// if it is a complete binary tree and every
// parent node is greater than or equal to
// its child nodes.
// Time Complexity:
// O(N)
// Space Complexity:
// O(H)
// (H = Height of the Tree)
/*
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};
*/

class Solution {
public:
    bool checkMaxHeap(Node* root){
        if(!root){
            return true;
        }
        if(root->left && root->data<root->left->data)return false;
        if(root->right && root->data<root->right->data)return false;
        return checkMaxHeap(root->left) && checkMaxHeap(root->right);
    }
    bool checkBinaryTree(Node* root,int index,int count){
        if(!root){
            return true;
        }
        if(index>=count)return false;
        return checkBinaryTree(root->left,2*index+1,count) && checkBinaryTree(root->right,2*index+2,count);
    }
    int countNodes(Node* root){
        if(!root){
            return 0;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    bool isHeap(Node* tree) {
        // Your code here
        int count=countNodes(tree);
        int index=0;
        return checkBinaryTree(tree,index,count) && checkMaxHeap(tree);
    }
};
