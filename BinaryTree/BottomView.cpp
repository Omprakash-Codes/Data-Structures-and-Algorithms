// Problem: Bottom View of Binary Tree
// Approach: Queue + Horizontal Distance
// Description:
// Print nodes visible from bottom of binary tree.
// Use level order traversal and horizontal distance.
// Store the latest node for every horizontal distance.
// Time Complexity: O(N)
// Space Complexity: O(N)
struct Node
{
    int data;
    Node* left;
    Node* right;
};
class Solution {
  public:
    void find(Node *root,int &leftmost,int &rightmost,int pos){
        if(!root){
            return;
        }
        leftmost=min(pos,leftmost);
        rightmost=max(pos,rightmost);

        find(root->left,leftmost,rightmost,pos-1);
        find(root->right,leftmost,rightmost,pos+1);
    }
    vector <int> bottomView(Node *root) {
        // Your Code Here
        if(!root){
            vector<int>ans;
            return ans;
        }
        int leftmost=0,rightmost=0;
        find(root,leftmost,rightmost,0);
        vector<int>ans(rightmost-leftmost+1);
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
            ans[index]=temp->data;
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
