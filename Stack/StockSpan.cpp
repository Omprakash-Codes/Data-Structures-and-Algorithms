// Problem: Stock Span Problem
// Approach: Monotonic Stack (Previous Greater Element)
// Description:
// For each day, calculate the number of consecutive days (including current day)
// before it where the stock price was less than or equal to the current day's price.
// Idea:
// Use a stack to keep track of indices of days with greater prices.
// if next greater is present for st.top element then push the answer in ans[st.top()]=st.top()-current index .
// then push the current index in stack
// after completing the traversal in Array
//if any element is present in stack then push these into ans-ans[st.top()]=st.top+1;
// Time Complexity: O(N)
// Space Complexity: O(N)
vector<int> calculateSpan(vector<int>& arr) {
    int n=arr.size();
    vector<int>span(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[i]>arr[st.top()]){
            span[st.top()]=st.top()-i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        span[st.top()]=st.top()+1;
        st.pop();
    }
    return span;
}
