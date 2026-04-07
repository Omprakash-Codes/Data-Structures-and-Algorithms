// Problem: Implement Circular Queue using Array
// Approach:
// Use modulo (%) to reuse empty spaces in array.
// Enqueue -> (rear + 1) % size
// Dequeue -> (front + 1) % size
// Full Condition: size == capacity
// Empty Condition: size==0
// Time Complexity: O(1)
// Space Complexity: O(N)
#include<iostream>
using namespace std;
class Queue{
    public:
    int front;
    int rear;
    int capacity;
    int size;
    int *queue;
    Queue(int s){
        queue=new int[s];
        front=rear=-1;
        size=0;
        capacity=s;
    }
    //for empty
    bool isempty(){
        return size==0;
    }
    //for full check
    bool isfull(){
        return size==capacity;
    }
    //for push in queue
    void push(int val){
        if(isempty()){
            front=rear=0;
            queue[rear]=val;
            size++;
            cout<<val<<"-pushed into queue\n";
        }else{
            if(isfull()){
                cout<<"queue is full\n";
                return;
            }
            rear=(rear+1)%capacity;
            queue[rear]=val;
            size++;
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
        size--;
        front=(front+1)%capacity;
        if(size==0){
            front=rear=-1;
        }
    }
    //for front element
    int getfront(){
        return queue[front];
    }
    //for size
    int getsize(){
        return size;
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
    cout<<q.getsize()<<endl;
    return 0;
}
