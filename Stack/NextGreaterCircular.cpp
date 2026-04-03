// Problem: Next Greater Element in Circular Array
// Approach: Stack + Traverse Twice
// Description:
// Given a circular array, find next greater element for each index.
// Circular means after last element, we go back to first.
// Trick:
// Traverse array twice (2 * N) from right to left.
// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i=0;i<2*n;i++){
            int index=i%n;
            while(!st.empty() && arr[index]>arr[st.top()]){
                ans[st.top()]=arr[index];
                st.pop();
            }
            st.push(index);
        }
        return ans;
    }
};
