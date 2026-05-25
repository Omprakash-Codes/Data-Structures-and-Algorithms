// Problem: Preorder Traversal using Morris Traversal
// Approach: Threaded Binary Tree
// Description:
// Perform preorder traversal without recursion
// and without stack.
// Morris Traversal temporarily creates links
// (threads) in the tree.
// Preorder Order:
// Root -> Left -> Right
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
    vector<int> preOrder(Node* root) {
        // code here
        //morris traversal method
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
                    ans.push_back(curr->data);
                    curr=curr->left;
                }else{
                    predecer->right=NULL;
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};
