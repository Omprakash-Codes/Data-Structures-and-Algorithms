// Problem: Find Height of Binary Tree
// Approach: Recursion
// Description:
// Find the height (maximum depth) of the binary tree.
// Height:
// Number of nodes in the longest path
// from root to leaf node.
// Formula:
// Height = 1 + max(leftHeight, rightHeight)
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
    int height(TreeNode* root) {
        // code here
        if(!root){
            return 0;
        }
        if(!root->left&&!root->right){
            return 0;
        }
       return 1+max(height(root->left),height(root->right));
    }
};
