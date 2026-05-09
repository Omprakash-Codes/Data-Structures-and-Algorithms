// Problem: Level Order Traversal of Binary Tree
// Approach: Queue (Breadth First Search)
// Description:
// Traverse the tree level by level from left to right.
// Use a queue to process nodes in FIFO order.
// Time Complexity: O(N)
// Space Complexity: O(N)
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    vector<vector<int>> levelOrderTraversal(TreeNode* root) {
        // code here
        vector<vector<int>>result;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>ans;
            int len=q.size();
            while(len){
            TreeNode* temp=q.front();
            q.pop();
            ans.push_back(temp->val);
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            len--;
            }
            result.push_back(ans);
        }

        return result;
    }
};
