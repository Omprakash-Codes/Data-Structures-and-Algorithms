// Problem: Count Non-Leaf Nodes in Binary Tree
// Approach: Recursion
// Description:
// Count total non-leaf nodes present in the binary tree.
// Non-Leaf Node:
// A node having at least one child.
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
    int countNonLeafNodes(TreeNode* root) {
        // code here
        if(!root){
            return 0;
        }
        if(!root->left&&!root->right){
            return 0;
        }
        return 1+countNonLeafNodes(root->left)+countNonLeafNodes(root->right);
        
    }
};
