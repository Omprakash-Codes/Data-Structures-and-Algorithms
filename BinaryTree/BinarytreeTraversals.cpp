// Problem: Create Binary Tree and Perform Traversals
// Approach: Recursion
// Description:
// Create a binary tree and perform:
// 1. Preorder Traversal  -> Root Left Right
// 2. Inorder Traversal   -> Left Root Right
// 3. Postorder Traversal -> Left Right Root
// Time Complexity: O(N)
// Space Complexity: O(H)
#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node *left,*right;
    node(int val){
        data=val;
        left=right=NULL;
    }
};
void preOrder(node *root){
    if(!root){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inorder(node *root){
    if(!root){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(node *root){
    if(!root){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main(){
    int x,leftvalue,rightvalue;
    queue<node *>q;
    cout<<"enter a root node of tree: ";
    cin>>x;
    node *root=new node(x);
    q.push(root);
    while (!q.empty())
    {
        node *temp=q.front();
        q.pop();
        //left value 
        cout<<"enter "<<temp->data<<" leftvalue:";
        cin>>leftvalue;
        if(leftvalue!=-1){
            temp->left=new node(leftvalue);
            q.push(temp->left);
        }
        //right value 
        cout<<"enter "<<temp->data<<" rightvalue:";
        cin>>rightvalue;
        if(rightvalue!=-1){
            temp->right=new node(rightvalue);
            q.push(temp->right);
        }
    }
    cout<<"pre-order: ";
    preOrder(root);
    cout<<endl;
    cout<<"in-order: ";
    inorder(root);
    cout<<endl;
    cout<<"post-order: ";
    postorder(root);
    return 0;
}
