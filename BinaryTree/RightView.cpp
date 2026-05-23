// Problem: Right View of Binary Tree
// Approach: Using recursion
// Description:
// Maintain the track of level and first go right then left
// when tree is viewed from right side.
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
    void rview(Node *root,vector<int>&ans,int level){
        if(!root){
            return;
        }
        if(ans.size()==level){
            ans.push_back(root->data);
        }
        rview(root->right,ans,level+1);
        rview(root->left,ans,level+1);
    }
    vector<int> rightView(Node *root) {
        // Your code here
        vector<int>ans;
        rview(root,ans,0);
        return ans;
    }
};
