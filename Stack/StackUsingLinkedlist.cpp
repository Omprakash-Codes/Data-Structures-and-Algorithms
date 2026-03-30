// Problem: Implement Stack using Linked List
// Approach:
// Use a linked list where insertion and deletion happen at the head.
// Push -> insert at beginning
// Pop  -> delete from beginning
// Time Complexity: O(1)
// Space Complexity: O(N)
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
class stack{
    public:
    node* head;
    int size;
    stack(){
        head=NULL;
        size=0;
    }
    //function for push in stack
    void push(int val){
        node* temp=new node(val);
        if(temp==NULL){
            cout<<"stack overflow";
            return;
        }
        temp->next=head;
        head=temp;
        size++;
        cout<<val<<"-pushed succesfully in stack \n";
    }
    //function for pop from stack
    void pop(){
        if(!head){
            cout<<"stack underflow";
            return;
        }
        cout<<head->data<<"-poped succesfully from stack \n";
        node* temp=head;
        head=head->next;
        delete temp;
        size--;
    }
    //function for top element
    int top(){
        return head->data;
    }
    //function for empty
    bool empty(){
        return head==NULL;
    }
    //function for size
    int sizes(){
        return size;
    }
};

int main(){
    stack s;
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(2);
    s.push(1);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    return 0;
}
