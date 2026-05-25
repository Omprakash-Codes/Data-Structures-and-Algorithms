// Problem: Inorder Traversal using Morris Traversal
// Approach: Threaded Binary Tree
// Description:
// Perform inorder traversal without recursion
// and without stack.
// Morris Traversal temporarily creates links
// (threads) in the tree.
// Inorder Order:
// Left -> Root -> Right
// Time Complexity: O(N)
// Space Complexity: O(1)
struct Node
{
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
    vector<int> inOrder(Node* root) {
        // code here
        //morris traversal
        vector<int>ans;
        if(!root){
            return ans;
        }
        Node *curr=root;
        while(curr){
            if(!curr->left){
                ans.push_back(curr->data);
                curr=curr->right;
            }else{
                Node *predecer=curr->left;
                while(predecer->right && predecer->right!=curr){
                    predecer=predecer->right;
                }
                if(!predecer->right){
                    predecer->right=curr;
                    curr=curr->left;
                }else{
                    predecer->right=NULL;
                    ans.push_back(curr->data);
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};
