// Problem: Merge Two BSTs
// Approach: Inorder Traversal + Merge Two Sorted Arrays
// Description:
// Merge two Binary Search Trees and
// return all elements in sorted order.
// BST Property:
// Inorder traversal of BST gives
// elements in sorted order.
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
    void inorder(Node* root,vector<int>&inord){
        if(!root){
            return;
        }
        inorder(root->left,inord);
        inord.push_back(root->data);
        inorder(root->right,inord);
    }
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int>first;
        vector<int>second;
        vector<int>ans;
        inorder(root1,first);
        inorder(root2,second);
        int i=0,j=0;
        while(i<first.size()&&j<second.size()){
            if(first[i]<second[j]){
                ans.push_back(first[i]);
                i++;
            }else{
                ans.push_back(second[j]);
                j++;
            }
        }
        while(i<first.size()){
            ans.push_back(first[i]);
            i++;
        }
        while(j<second.size()){
            ans.push_back(second[j]);
            j++;
        }
        return ans;
    }
};
