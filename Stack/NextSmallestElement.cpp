// Problem: Next Smaller Element
// Approach: Stack (Monotonic Increasing Stack)
// Description:
// For each element, find the next smaller element to its right.
// If no smaller element exists, return -1.
// Maintain a stack that keeps elements in increasing order.
// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    vector<int> nextSmallerElement(vector<int> &arr, int n) {
        // Your code here
        stack<int>st;
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                ans[st.top()]=arr[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
