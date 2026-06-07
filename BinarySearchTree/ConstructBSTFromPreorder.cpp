// Problem: Construct Binary Search Tree From Preorder Traversal
// Approach: Recursion with Range
// Description:
// Construct a BST from its preorder traversal.
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
TreeNode* build(vector<int>&preorder,int&index,int minval,int maxval){
    if(index>=preorder.size()||preorder[index]<minval||preorder[index]>maxval){
        return NULL;
    }
    TreeNode* root=new TreeNode(preorder[index]);
    index++;
    root->left=build(preorder,index,minval,root->val);
    root->right=build(preorder,index,root->val,maxval);
    return root;
} 
TreeNode* bstFromPreorder(vector<int>& preorder) {
    int index=0;
    return build(preorder,index,INT_MIN,INT_MAX);
}
