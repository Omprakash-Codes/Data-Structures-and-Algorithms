// Problem: Minimum Distance Between BST Nodes
// Approach: Inorder Traversal
// Description:
// Find the minimum absolute difference
// between values of any two nodes in a BST.
// BST Property:
// Inorder traversal gives sorted order.
// Time Complexity: O(N)
// Space Complexity: O(H)
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
class Solution {
public:
    void find(TreeNode* root,int&mindiff,int&prev){
        if(!root){
            return;
        }
        find(root->left,mindiff,prev);
        if(prev!=-1){
            mindiff=min(mindiff,root->val-prev);
        }
        prev=root->val;
        find(root->right,mindiff,prev);
    }
    int minDiffInBST(TreeNode* root) {
        int mindiff=INT_MAX;
        int prev=-1;
        find(root,mindiff,prev);
        return mindiff;
    }
};
