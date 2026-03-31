// Problem: Minimum Add to Make Parentheses Valid
// Approach: Stack / Counter (Optimized)
// Description:
// Given a string of parentheses, find minimum number of brackets to add
// to make it valid.
// Rules:
// - '(' needs a matching ')'
// - ')' needs a matching '('
// Count unmatched brackets.
// Time Complexity: O(N)
// Space Complexity: O(1)
int minAddToMakeValid(string s) {
    //1st approch
    stack<char>st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            st.push(')');
        }
        else{
            if(!st.empty() && st.top()==s[i]){
                st.pop();
            }
            else{
                st.push('(');
            }
        }
    }
    return st.size();
    //2nd approch
     int left=0,right=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            left++;
        }
        else{
            if(left){
                 left--;
            }
            else{
                right++;
             }
         }
     }
     return left+right;
}
