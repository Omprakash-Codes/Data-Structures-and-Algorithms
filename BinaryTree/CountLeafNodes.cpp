// Problem: Count Leaf Nodes in Binary Tree
// Approach: Recursion
// Description:
// Count total leaf nodes present in the binary tree.
// Leaf Node:
// A node having no left and no right child.
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
    int countLeaves(TreeNode* root) {
        // code here
        if(!root){
            return 0;
        }
        if(!root->left && !root->right){
            return 1;
        }
        return countLeaves(root->left)+countLeaves(root->right);
    }
};
