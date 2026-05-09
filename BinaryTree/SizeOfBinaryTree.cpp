// Problem: Find Size of Binary Tree
// Approach: Recursion
// Description:
// Find total number of nodes present in the binary tree.
// Formula:
// Size = Left Subtree + Right Subtree + 1 (current node)
// Time Complexity: O(N)
// Space Complexity: O(H)
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    int sizeOfBinaryTree(TreeNode* root) {
        // code here
        if(!root){
            return 0;
        }
       return 1+sizeOfBinaryTree(root->left)+sizeOfBinaryTree(root->right);
    }
};
