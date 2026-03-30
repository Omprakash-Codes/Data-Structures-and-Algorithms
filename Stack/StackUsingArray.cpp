// Problem: Implement Stack using Array
// Approach:
// Use an array and maintain a top pointer.
// Push -> insert element at top
// Pop  -> remove element from top
// Time Complexity: O(1)
#include<iostream>
using namespace std;
class stack{
    public:
    int st[100];
    int index;
    stack(){
        index=-1;
    }
    //function for push in stack
    void push(int val){
        if(index==99){
            cout<<"stack overflow";
            return;
        }
        index++;
        st[index]=val;
        cout<<val<<"-pushed in stack"<<endl;;
    }
    //function for pop
    void pop(){
        if(index==-1){
            cout<<"stack underflow";
            return;
        }
        cout<<st[index]<<"-poped succesfully from stack"<<endl;
        index--;
    }
    //function for Top element
    int Top(){
        return st[index];
    }
    //function for check empty
    bool empty(){
        return index==-1;
    }
    //function for check size
    int size(){
        return index+1;
    }

};
int main(){
    stack s;
    s.push(5);
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    return 0;
}
