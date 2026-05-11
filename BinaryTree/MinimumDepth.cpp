// Problem: Find Minimum Depth of Binary Tree
// Approach: Recursion
// Description:
// Find the minimum depth from root node
// to nearest leaf node.
// Minimum Depth:
// Number of nodes in shortest path
// from root to leaf node.
// Time Complexity: O(N)
// Space Complexity: O(H)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
int minDepth(TreeNode* root) {
    if(!root){
        return 0;
    }
    if(!root->left){
        return 1+minDepth(root->right);
    }
    if(!root->right){
        return 1+minDepth(root->left);
    }
   return 1+min(minDepth(root->left),minDepth(root->right));
}
