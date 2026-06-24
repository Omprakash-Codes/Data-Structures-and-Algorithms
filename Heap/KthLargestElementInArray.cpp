// Problem: Kth Largest Element in an Array
// Approach:
// Min Heap of Size K
// Description:
// Find the Kth largest element in an array.
// Maintain a min heap containing the K largest
// elements seen so far. The root of the heap
// represents the Kth largest element.
// Time Complexity:
// O(k log K)
// Space Complexity:
// O(K)
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<k;i++){
        pq.push(nums[i]);
    }
    for(int i=k;i<nums.size();i++){
        if(nums[i]>pq.top()){
            pq.pop();
            pq.push(nums[i]);
        }
    }
    return pq.top();
}
