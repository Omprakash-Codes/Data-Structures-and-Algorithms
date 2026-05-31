// Problem: Search Element in Binary Search Tree
// Approach: Recursion
// Description:
// Search a given key in BST using BST property.
// BST Property:
// Left Subtree  < Root
// Right Subtree > Root
// Time Complexity:
// Average: O(log N)
// Worst: O(N)
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
    // Function to search a node in BST.
    bool search(Node* root, int x) {
        // Your code here
        if(!root){
            return 0;
        }
        if(x==root->data){
            return 1;
        }
        if(x<root->data){
           return search(root->left,x);
        }else{
           return search(root->right,x);
        }
    }
};
