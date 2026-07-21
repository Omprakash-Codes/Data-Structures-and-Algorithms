// Problem: BST to Max Heap
// Approach:
// Inorder Traversal + Postorder Traversal
// Description:
// Convert a Binary Search Tree (BST) into a
// Max Heap while preserving the original
// Time Complexity:
// O(N)
// Space Complexity:
// O(N)
/*
struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};
*/

class Solution {
public:
    void buildmaxHeap(Node* &root,vector<int>i,int &index){
        if(!root || index<0){
            return;
        }
        root->data=i[index];
        index--;
        buildmaxHeap(root->right,i,index);
        buildmaxHeap(root->left,i,index);
    }
    void inorder(Node* root,vector<int>&i){
        if(!root){
            return;
        }
        inorder(root->left,i);
        i.push_back(root->data);
        inorder(root->right,i);
    }
    void convertToMaxHeapUtil(Node* root) {
        // Your code here
        vector<int>i;
        inorder(root,i);
        int index=i.size()-1;
        buildmaxHeap(root,i,index);
    }
};
