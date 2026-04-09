// Problem: Implement Stack using Queue
// Approach: Using two Queue
// Description:
// Stack follows LIFO, Queue follows FIFO.
// Steps:
// 1. Push element into Non empty queue
// 2. Pop from if 1st queue is not empty then push all element in 2nd queue except last one remove front of 1st queue and 
// -vice versa
// Time Complexity:
// Push: O(1)
// Pop: O(N)
// Space Complexity: O(N)
class MyStack {
public:
    queue<int>q1;
    queue<int>q2;
    MyStack() {
        
    }
    
    void push(int x) {
        if(!q1.empty()){
            q1.push(x);
        }
        else{
            q2.push(x);
        }
    }
    
    int pop() {
        if(q1.empty() && q2.empty()){
            return -1;
        }
        else if(!q1.empty()){
            while(q1.size()>1){
                q2.push(q1.front());
                q1.pop();
            }
            int element=q1.front();
            q1.pop();
            return element;
        }
        else{
            while(q2.size()>1){
                q1.push(q2.front());
                q2.pop();
            }
            int element=q2.front();
            q2.pop();
            return element;
        }
    }
    
    int top() {
        if(q1.empty()&&q2.empty()){
            return -1;
        }
        else if(!q2.empty()){
            return q2.back();
        }else{
            return q1.back();
        }
    }
    
    bool empty() {
        return q1.empty()&&q2.empty();
    }
};
