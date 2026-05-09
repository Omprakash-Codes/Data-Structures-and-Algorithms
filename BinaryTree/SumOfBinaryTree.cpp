// Problem: Find Sum of Nodes in Binary Tree
// Approach: Recursion
// Description:
// Find the sum of all nodes present in the binary tree.
// Formula:
// Sum = Left Subtree Sum + Right Subtree Sum + Current Node
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
    int sumOfBinaryTree(TreeNode* root) {
        // code here
        if(!root){
            return 0;
        }
       return root->val+sumOfBinaryTree(root->left)+sumOfBinaryTree(root->right);
    }
};
