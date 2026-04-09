// Problem: Implement Queue using Stack
// Approach: Using Two Stacks
// Description:
// Queue follows FIFO, but stack follows LIFO.
// Use two stacks to simulate queue behavior.
// Steps:
// 1. Push element into stack1
// 2. For dequeue:
//    - Move all elements from stack1 to stack2
//    - Pop from stack2
// Time Complexity:
// Enqueue: O(1)
// Dequeue: O(N)
// Space Complexity: O(N)

class MyQueue {
public:
    stack<int>st1;
    stack<int>st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(st1.empty()&&st2.empty()){
            return -1;
        }
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            int element=st2.top();
            st2.pop();
            return element;
        }else{
            int element=st2.top();
            st2.pop();
            return element;
        }
    }
    
    int peek() {
        if(st1.empty()&&st2.empty()){
            return -1;
        }
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            return st2.top();
        }else{
            return st2.top();
        }
    }
    
    bool empty() {
        return st1.empty()&&st2.empty();
    }
};
