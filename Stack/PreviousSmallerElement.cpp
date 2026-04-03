// Problem: Previous Smaller Element
// Approach: Stack (Monotonic Increasing Stack)
// Description:
// For each element, find the previous smaller element to its left.
// If no smaller element exists, return -1.
// Traverse from left to right and maintain increasing stack.
// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    vector<int> nextSmallerOnLeft(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        stack<int>st;
        vector<int>ans(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]<arr[st.top()]){
                ans[st.top()]=arr[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
