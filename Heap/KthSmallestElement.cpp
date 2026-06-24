// Problem: Kth Smallest Element
// Approach:
// Max Heap of Size K
// Description:
// Find the Kth smallest element in an array.
// Maintain a max heap containing the K smallest
// elements seen so far. The root of the heap
// represents the Kth smallest element.
// Time Complexity:
// O(k log K)
// Space Complexity:
// O(K)
int kthSmallest(vector<int> &arr, int k) {
    // Write your code here
    priority_queue<int>pq;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    for(int i=k;i<arr.size();i++){
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}
