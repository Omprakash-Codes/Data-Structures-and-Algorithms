// Problem: Find Common Nodes in Two BSTs
// Approach: Inorder Traversal + Two Pointer
// Description:
// Find all common nodes present in
// two Binary Search Trees.
// Time Complexity: O(N + M)
// Space Complexity: O(N + M)
/**
 * Definition for a binary tree node.
 * struct Node {
 *     int data;
 *     Node *left;
 *     Node *right;
 *     Node(int x) : data(x), left(NULL), right(NULL) {}
 * }; 

class Solution {
public:
    void inorder(Node *root,vector<int>&inord){
        if(!root){
            return;
        }
        inorder(root->left,inord);
        inord.push_back(root->data);
        inorder(root->right,inord);
    }
    vector<int> findCommon(Node *root1, Node *root2) {
        // Your code here
        vector<int>first;
        vector<int>second;
        vector<int>ans;
        inorder(root1,first);
        inorder(root2,second);
        int i=0,j=0;
        while(i<first.size()&&j<second.size()){
            if(first[i]==second[j]){
                ans.push_back(first[i]);
                i++;
                j++;
            }else if(first[i]<second[j]){
                i++;
            }else{
                j++;
            }
        }
        return ans;
    }
};
