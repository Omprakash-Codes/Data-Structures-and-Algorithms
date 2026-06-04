// Problem: Convert Sorted Array to Binary Search Tree
// Approach: Divide and Conquer
// Description:
// Construct a height-balanced BST
// from a sorted array.
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
    Node* build(vector<int>arr,int start,int end){
        if(start>end){
            return NULL;
        }
        int mid=start+(end-start)/2;
        Node* root=new Node(arr[mid]);
        root->left=build(arr,start,mid-1);
        root->right=build(arr,mid+1,end);

        return root;
    }
    Node* sortedArrayToBST(vector<int>& nums) {
        // Your code here
        return build(nums,0,nums.size()-1);
    }
};
