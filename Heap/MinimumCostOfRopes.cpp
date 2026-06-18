// Problem: Minimum Cost of Ropes
// Approach:
// Min Heap (Priority Queue)
// Description:
// Given N ropes, connect all ropes into a
// single rope with minimum possible cost.
// The cost of connecting two ropes equals
// the sum of their lengths.
// Time Complexity:
// O(N log N)
// Space Complexity:
// O(N)
class Solution {
public:
    long long minCost(vector<long long>& arr) {
        // code here
        priority_queue<long long,vector<long long>,greater<long long>>pq(arr.begin(),arr.end());
        long long cost=0;
        while(pq.size()>1){
            long long first=pq.top();
            pq.pop();
            long long second=pq.top();
            pq.pop();
            cost+=first+second;
            pq.push(first+second);
        }
        return cost;
    }
};
