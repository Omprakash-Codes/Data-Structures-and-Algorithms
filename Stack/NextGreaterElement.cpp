// Problem: Next Greater Element
// Approach: Stack (Monotonic Stack)
// Description:
// For each element, find the next greater element to its right.
// If no greater element exists, return -1.
// Use stack to keep elements in decreasing order.
// Time Complexity: O(N)
// Space Complexity: O(N)
vector<int> nextLargerElement(vector<int>& arr) {
    stack<int>st;
    vector<int>ans(arr.size(),-1);
    for(int i=0;i<arr.size();i++){
        while(!st.empty() && arr[i]>arr[st.top()]){
            ans[st.top()]=arr[i];
            st.pop();
        }
        st.push(i);
    }   
    return ans;
}
