// Problem: Sum of K Smallest Elements in BST
// Approach: Inorder Traversal
// Description:
// Find the sum of first k smallest elements
// in a Binary Search Tree.
// BST Property:
// Inorder traversal gives elements
// in sorted order.
// Time Complexity: O(N)
// Space Complexity: O(H)
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    void findSum(Node* root,int&k,int&add){
        if(!root||k<0){
            return;
        }
        findSum(root->left,k,add);
        k--;
        if(k>=0){
            add+=root->data;
        }
        findSum(root->right,k,add);
    }
    int sum(Node* root, int k) {
        // Your code here
        int add=0;
        findSum(root,k,add);
        return add;
    }
};
