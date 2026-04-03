// Problem: Previous Greater Element
// Approach: Stack (Monotonic Decreasing Stack)
// Description:
// For each element, find the previous greater element to its left.
// If no greater element exists, return -1.
// Traverse from left to right and maintain decreasing stack.
// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    vector<int> previousGreaterElement(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]>arr[st.top()]){
                ans[st.top()]=arr[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
