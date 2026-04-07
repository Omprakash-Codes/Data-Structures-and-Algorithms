// Problem: Implement Queue using Linked List
// Approach:
// Use a linked list with front and rear pointers.
// Enqueue(push) -> insert at rear
// Dequeue(pop) -> remove from front
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
class Queue{
    public:
    node* front;
    node* rear;
    int size;
    Queue(){
        front=rear=NULL;
        size=0;
    }
    //for empty
    bool isempty(){
        return front==NULL;
    }
    //for pushed
    void push(int val){
        if(isempty()){
            cout<<val<<"-pushed in queue\n";
            front=new node(val);
            size++;
            rear=front;
        }else{
            cout<<val<<"-pushed in queue\n";
            rear->next=new node(val);
            size++;
            rear=rear->next;
        }
    }
    //for pop
    void pop(){
        if(isempty()){
            cout<<"queue is empty";
            return;
        }
        cout<<front->data<<"-poped from queue\n";
        size--;
        node* temp=front;
        front=front->next;
        delete temp;
    }
    //for front element
    int getfront(){
        return front->data;
    }
    //for size
    int getsize(){
        return size;
    }
};
int main(){
    Queue q;
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
}
