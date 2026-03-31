// Problem: Make Array Beautiful
// Approach: Stack
// Description:
// Remove adjacent elements if one is negative and the other is positive.
// Traverse the array and use a stack:
// - If current element and stack top have opposite signs → remove both
// - Otherwise push current element
// Time Complexity: O(N)
// Space Complexity: O(N)
vector<int> makeBeautiful(vector<int> arr) {
    //write your code here
    stack<int>st;
    vector<int>ans;
    for(int i=0;i<arr.size();i++){
        if(st.empty()){
            st.push(arr[i]);
        }
        else{
            if((st.top()<0 && arr[i]>=0)||(st.top()>=0 && arr[i]<0)){
                st.pop();
            }
            else{
                st.push(arr[i]);
            }
        }
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
