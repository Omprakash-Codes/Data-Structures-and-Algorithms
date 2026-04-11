// Problem: Implement Deque using Doubly Linked List
// Approach:
// Use a doubly linked list with front and rear pointers.
// Deque supports insertion and deletion from both ends:
// - pushFront
// - pushBack
// - popFront
// - popBack
// - getFront
// - getRear
// Time Complexity: O(1) for all operations
// Space Complexity: O(N)
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next,*prev;
    node(int val){
        data=val;
        next=prev=NULL;
    }
};
class Deque{
    public:
    node* front;
    node* rear;
    int size;
    Deque(){
        front=rear=NULL;
        size=0;
    }
    //for empty
    bool isempty(){
        return size==0;
    }
    //for push in front
    void pushfront(int val){
        if(isempty()){
            front=rear=new node(val);
            size++;
        }else{
            front->prev=new node(val);
            front->prev->next=front;
            front=front->prev;
            size++;
        }
        cout<<val<<"-pushed in front of Deque\n";
    }
    //for push in rear
    void pushrear(int val){
        if(isempty()){
            front=rear=new node(val);
            size++;
        }else{
            rear->next=new node(val);
            rear->next->prev=rear;
            rear=rear->next;
            size++;
        }
        cout<<val<<"-pushed in rear of Dequq\n";
    }
    //for pop from front
    void popfront(){
        if(isempty()){
            cout<<"Deque is empty\n";
            return;
        }
        cout<<front->data<<"-poped from front of Deque\n";
        front=front->next;
        delete front->prev;
        front->prev=NULL;
        size--;
    }
    //for pop from rear
    void poprear(){
        if(isempty()){
            cout<<"Dequq is empty\n";
            return;
        }
        cout<<rear->data<<"-poped from rear of Deque\n";
        rear=rear->prev;
        delete rear->next;
        rear->next=NULL;
        size--;
    }
    //for get front element
    int getfront(){
        return front->data;
    }
    //for get rear
    int getrear(){
        return rear->data;
    }
    //for get size
    int getsize(){
        return size;
    }
};  

int main(){
    Deque d;
    d.pushfront(8);
    d.pushfront(7);
    d.pushfront(6);
    cout<<d.getsize()<<endl;
    cout<<d.getfront()<<endl;
    cout<<d.getrear()<<endl;
    d.pushrear(9);
    d.pushrear(10);
    d.poprear();
    cout<<d.getsize()<<endl;
    cout<<d.getrear()<<endl;
    cout<<d.getfront()<<endl;
    return 0;
}
