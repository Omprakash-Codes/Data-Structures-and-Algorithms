/*
struct Node
{
  int data;
  Node* left;
  Node* right;
  Node(int x){
      data = x;
      left = right = NULL;
  }
};
*/

class Solution {
public:
    int find(vector<int> &inorder,int start,int end,int val){
        for(int i=start;i<=end;i++){
            if(inorder[i]==val){
                return i;
            }
        }
    }
    Node *build(vector<int> &inorder,vector<int> &preorder,int start,int end,int&pos){
        if(start>end || pos>=preorder.size()){
            return NULL;
        }
        Node *root=new Node(preorder[pos]);
        int val=preorder[pos];
        int index=find(inorder,start,end,val);
        pos++;
        root->left=build(inorder,preorder,start,index-1,pos);
        root->right=build(inorder,preorder,index+1,end,pos);
        return root;
    }
    Node* buildTree(vector<int> inorder, vector<int> preorder) {
        // Your code here
        int pos=0;
        return build(inorder,preorder,0,inorder.size()-1,pos);
    }
};
