// Problem: Search Element in Binary Tree
// Approach: Recursion
// Description:
// Search a given value in the binary tree.
// Traverse left and right subtree recursively.
// If value found, return true.
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
TreeNode* searchBST(TreeNode* root, int val) {
    if(!root){
        return NULL;
    }
    if(root->val==val){
        return root;
    }
    TreeNode* rightside=searchBST(root->right,val);
    if(rightside){
        return rightside;
    }
    return searchBST(root->left,val);
}
