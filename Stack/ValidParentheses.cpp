// Problem: Valid Parentheses
// Approach: Stack
// Description:
// Given a string containing '(', ')', '{', '}', '[' and ']',
// check if the input string is valid.
// A string is valid if:
// 1. Open brackets are closed by the same type.
// 2. Open brackets are closed in correct order.
// Time Complexity: O(N)
// Space Complexity: O(N)
bool isValid(string& s) {
    stack<char>st;
    for(int i=0;i<s.size();i++){
        if(st.empty()||s[i]=='('||s[i]=='['||s[i]=='{'){
            if(s[i]=='('){
                st.push(')');
            }else if(s[i]=='['){
                st.push(']');
            }else if(s[i]=='{'){
                st.push('}');
            }else{
                return 0;
            }
        }
        else{
            if(st.top()==s[i]){
                st.pop();
            }else{
                return 0;
            }
        }
    }
    return st.empty();
}
