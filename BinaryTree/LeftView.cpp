// Problem: Left View of Binary Tree
// Approach: Using recursion
// Description:
// Maintain the Track of Level
// when tree is viewed from left side.
// Time Complexity: O(N)
// Space Complexity: O(N)

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};


class Solution {
public:
    void lview(Node *root,vector<int>&ans,int level){
        if(!root){
            return;
        }
        if(ans.size()==level){
            ans.push_back(root->data);
        }
        lview(root->left,ans,level+1);
        lview(root->right,ans,level+1);
    }
    vector<int> leftView(Node *root) {
        // Your code here
        vector<int>ans;
        lview(root,ans,0);
        return ans;
    }
};
