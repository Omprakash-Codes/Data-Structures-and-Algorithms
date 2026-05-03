// Problem: Maximum of Minimum for Every Window Size
// Approach: Monotonic Stack
// Description:
// For every window size from 1 to N,
// find the maximum among all minimum elements of subarrays.
// Idea:
// For each element:
// - Find Previous Smaller Element
// - Find Next Smaller Element
// This gives the window size where current element is minimum.
// Time Complexity: O(N)
// Space Complexity: O(N)
vector<int> maxOfMin(vector<int>& arr) {
    // your code here
    int n=arr.size();
    vector<int>NSR(n,n);
    stack<int>st1;
    //for calculate nsr
    for(int i=0;i<n;i++){
        while(!st1.empty()&&arr[i]<arr[st1.top()]){
            NSR[st1.top()]=i;
            st1.pop();
        }
        st1.push(i);
    }
    vector<int>NSL(n,-1);
    stack<int>st2;
    //for calculate nsl
    for(int i=n-1;i>=0;i--){
        while(!st2.empty()&&arr[i]<arr[st2.top()]){
            NSL[st2.top()]=i;
            st2.pop();
        }
        st2.push(i);
    }
    vector<int>ans(n);
    //main calculation
    for(int i=0;i<n;i++){
        int len=NSR[i]-NSL[i]-1;
        ans[len-1]=max(arr[i],ans[len-1]);
    }
    for(int i=n-2;i>=0;i--){
        ans[i]=max(ans[i],ans[i+1]);
    }
    return ans;
}
