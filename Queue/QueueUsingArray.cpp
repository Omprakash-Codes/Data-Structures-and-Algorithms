// Problem: Implement Queue using Array
// Approach:
// Use an array with two pointers: front and rear.
// Enqueue(push) -> insert element at rear
// Dequeue(pop) -> remove element from front
// Time Complexity: O(1)
// Space Complexity: O(N)
#include<iostream>
using namespace std;
class Queue{
    public:
    int front;
    int rear;
    int capacity;
    int *queue;
    Queue(int size){
        queue=new int[size];
        front=rear=-1;
        capacity=size;
    }
    //for empty
    bool isempty(){
        return rear==-1;
    }
    //for full check
    bool isfull(){
        return rear==capacity-1;
    }
    //for push in queue
    void push(int val){
        if(isempty()){
            front=rear=0;
            queue[rear]=val;
            cout<<val<<"-pushed into queue\n";
        }else{
            if(isfull()){
                cout<<"queue is full\n";
                return;
            }
            rear=rear+1;
            queue[rear]=val;
            cout<<val<<"-pushed into queue\n";
        }
    }
    //for pop in queue
    void pop(){
        if(isempty()){
            cout<<"queue is empty\n";
            return;
        }
        cout<<queue[front]<<"-poped from queue\n";
        front=front+1;
        if(front>rear){
            front=rear=-1;
        }
    }
    //for front element
    int getfront(){
        return queue[front];
    }
    //for size
    int getsize(){
        return rear-front+1;
    }
};
int main(){
    Queue q(4);
    q.push(8);
    q.push(4);
    q.push(2);
    q.push(9);
    q.pop();
    q.pop();
    q.push(10);
    return 0;
}
