// Problem: Postorder Traversal using Morris Traversal
// Approach: Morris Traversal + Reverse Path
// Description:
// Perform postorder traversal without recursion
// and without stack.
// Postorder Order:
// Left -> Right -> Root
// Time Complexity: O(N)
// Space Complexity: O(1)
 // Definition for a binary tree node.
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root){
            return ans;
        }
        TreeNode *curr=root;
        while(curr){
            if(!curr->right){
                ans.push_back(curr->val);
                curr=curr->left;
            }else{
              TreeNode *predecer=curr->right;
              while(predecer->left && predecer->left!=curr){
                predecer=predecer->left;
              }
              if(!predecer->left){
                predecer->left=curr;
                ans.push_back(curr->val);
                curr=curr->right;
              }else{
                predecer->left=NULL;
                curr=curr->left;
              }
            }  
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
