// Problem: Largest Rectangle in Histogram
// Approach: Monotonic Stack (Next Smaller Left & Right)
// Description:
// Given heights of histogram bars, find the largest rectangle area.
// Idea:
// For each bar, find:
// 1. Previous Smaller Element (left boundary)
// 2. Next Smaller Element (right boundary)
// Width = right[i] - left[i] - 1
// Area = height[i] * width
// Time Complexity: O(N)
// Space Complexity: O(N)
int largestRectangleArea(vector<int>& heights) {
    stack<int>st;
    int n=heights.size();
    vector<int>NSR(n);
    vector<int>NSL(n,-1);
    //first find next smallest on right side and push index of next smallest element
    for(int i=0;i<n;i++){
        while(!st.empty() && heights[i]<heights[st.top()]){
            NSR[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    //then jis element ka koi nsr nhi ho wha size of array dal do
    while(!st.empty()){
        NSR[st.top()]=n;
        st.pop();
    }
    //then find next smallest on left side and push index of next smallest element
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && heights[i]<heights[st.top()]){
            NSL[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    //then find the maxarea with help of nsr and nsl
    int maxarea=0;
    for(int i=0;i<n;i++){
        maxarea=max(maxarea,(NSR[i]-NSL[i]-1)*heights[i]);
    }
    return maxarea;
}
