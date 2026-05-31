// Problem: Binary Search Tree Implementation
// Approach: Recursive Insertion
// Description:
// Create a Binary Search Tree and insert nodes.
// BST Property:
// Left Subtree  < Root
// Right Subtree > Root
// Time Complexity:
// Average: O(log N)
// Worst: O(N)
// Space Complexity: O(H)
#include<iostream>
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
node* build(node* root,int val){
    if(!root){
        return new node(val);
    }
    if(val<root->data){
       root->left=build(root->left,val);
    }
    else{
        root->right=build(root->right,val);
    }
}
void inorder(node* root){
    if(!root){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    int arr[]={10,3,7,18,12,2,20,10};
    node* root=NULL;
    for(int i=0;i<8;i++){
       root=build(root,arr[i]);
    }
    inorder(root);
}
