// Problem: Construct Binary Search Tree from Postorder Traversal
// Approach: Recursion with Range
// Description:
// Construct a BST from its postorder traversal.
// BST Property:
// Left Subtree < Root < Right Subtree
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

class Solution {
public:
    TreeNode* build(vector<int>&postorder,int&index,int minval,int maxval){
        if(index<0||postorder[index]<minval||postorder[index]>maxval){
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[index]);
        index--;
        root->right=build(postorder,index,root->val,maxval);
        root->left=build(postorder,index,minval,root->val);
        return root;
    }
    TreeNode* bstFromPostorder(vector<int>& postorder) {
        // Your code here
        int index=postorder.size()-1;
        return build(postorder,index,INT_MIN,INT_MAX);
    }
};
