// Problem: Convert Binary Tree into Mirror Tree
// Approach: Recursion
// Description:
// Convert the binary tree into its mirror form
// by swapping left and right child of every node.
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
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* root) {
        // code here
        if(!root){
            return;
        }
        Node *temp=root->left;
        root->left=root->right;
        root->right=temp;
        mirror(root->left);
        mirror(root->right);
    }
};
