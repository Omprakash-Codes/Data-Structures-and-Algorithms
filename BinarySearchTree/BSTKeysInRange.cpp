// Problem: BST Keys in a Range
// Approach: Inorder Traversal + BST Property
// Description:
// Print all keys lying in the range [low, high]
// in sorted order.
// BST Property:
// Left Subtree < Root < Right Subtree
// Time Complexity: O(N)
// Space Complexity: O(H)
 * Definition for a binary tree node.
 * struct Node {
 *     int data;
 *     Node *left;
 *     Node *right;
 *     Node(int x) : data(x), left(NULL), right(NULL) {}
 * };

class Solution {
public:
    void find(Node* root,int&low,int&high,vector<int>&ans){
        if(!root){
            return;
        }
        find(root->left,low,high,ans);
        if(root->data>=low && root->data<=high){
            ans.push_back(root->data);
        }
        find(root->right,low,high,ans);
    }
    vector<int> printNearNodes(Node *root, int low, int high) {
        // Your code here
        vector<int>ans;
        find(root,low,high,ans);
        return ans;
    }
};
