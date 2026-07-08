// Problem: Kth Largest Element in a Stream
// Approach:
// Min Heap of Size K
// Description:
// Design a data structure that continuously
// returns the Kth largest element as new
// elements are added to the stream.
// Maintain a min heap of size K containing
// the K largest elements seen so far.
// Time Complexity:
// Constructor : O(N log K)
// Add Element : O(log K)
// Space Complexity:
// O(K)
vector<int> kthLargest(vector<int>& arr, int k) {
    vector<int>ans(k-1,-1);
    priority_queue<int,vector<int>,greater<int>>pq(arr.begin(),arr.begin()+k);
    ans.push_back(pq.top());
    for(int i=k;i<arr.size();i++){
        if(arr[i]>pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
        ans.push_back(pq.top());
    }
    return ans;
}
