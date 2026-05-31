// Problem: Delete a Node from Binary Search Tree
// Approach: Recursion
// Description:
// Delete a given node from BST while
// maintaining BST properties.
// Cases:
// 1. Leaf Node
// 2. Node with One Child
// 3. Node with Two Children
// Time Complexity:
// Average: O(log N)
// Worst: O(N)
// Space Complexity: O(H)
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    Node* find(Node* root){
        Node* curr=root->left;
        while(curr->right){
            curr=curr->right;
        }
        return curr;
    }
    Node* deleteNode(Node* root, int x) {
        // Your code here
        if(!root){
            return NULL;
        }
        if(x<root->data){
            root->left=deleteNode(root->left,x);
        }
        else if(x>root->data){
            root->right=deleteNode(root->right,x);
        }
        else{
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }
            else if(!root->right){
                Node* temp=root->left;
                delete root;
                return temp;
            }
            else if(!root->left){
                Node* temp=root->right;
                delete root;
                return temp;
            }
            else{
                Node* predecer=find(root);
                root->data=predecer->data;
                root->left=deleteNode(root->left,predecer->data);
            }
        }
        return root;
    }
};
