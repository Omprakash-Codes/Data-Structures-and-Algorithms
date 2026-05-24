// Problem: Top View of Binary Tree
// Approach: Queue + Horizontal Distance
// Description:
// Print nodes visible from top of binary tree.
// Use queue for level order traversal
// and horizontal distance to track positions.
// Time Complexity: O(N)
// Space Complexity: O(N)
struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    void find(Node *root,int &leftmost,int &rightmost,int pos){
        if(!root){
            return;
        }
        leftmost=min(leftmost,pos);
        rightmost=max(rightmost,pos);
        find(root->left,leftmost,rightmost,pos-1);
        find(root->right,leftmost,rightmost,pos+1);
    }
    vector<int> topView(Node *root)
    {
        //Your code here
        if(!root){
            vector<int>ans;
            return ans;
        }
        int leftmost=0,rightmost=0;
        find(root,leftmost,rightmost,0);

        vector<int>ans(rightmost-leftmost+1);
        vector<bool>indicator(rightmost-leftmost+1,0);
        queue<Node*>q;
        queue<int>position;
        q.push(root);
        position.push(0);
        while(!q.empty()){
            Node *temp=q.front();
            q.pop(); 
            int pos=position.front();
            position.pop();
            int index=pos-leftmost;
            if(indicator[index]==0){
                ans[index]=temp->data;
                indicator[index]=1;
            }
            if(temp->left){
                q.push(temp->left);
                position.push(pos-1);
            }
            if(temp->right){
                q.push(temp->right);
                position.push(pos+1);
            }
        }
        return ans;
    }
};
