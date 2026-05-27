// Problem: Construct Binary Tree from Inorder and Postorder Traversal
// Approach: Recursion
// Description:
// Build binary tree using:
// 1. Inorder Traversal   -> Left Root Right
// 2. Postorder Traversal -> Left Right Root
// Time Complexity: O(N)
// Space Complexity: O(N)
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };

int find(vector<int>&inorder,int end,int start,int val){
    for(int i=start;i<=end;i++){
        if(inorder[i]==val){
            return i;
        }
    }
}
TreeNode *build(vector<int>&inorder,vector<int>&postorder,int start,int end,int&pos){
    if(end>start || pos<0){
        return NULL;
    }
    TreeNode* root=new TreeNode(postorder[pos]);
    int val=postorder[pos];
    int index=find(inorder,start,end,val);
    pos--;
    root->right=build(inorder,postorder,start,index+1,pos);
    root->left=build(inorder,postorder,index-1,end,pos);
    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int pos=postorder.size()-1;
   return build(inorder,postorder,postorder.size()-1,0,pos);
}
