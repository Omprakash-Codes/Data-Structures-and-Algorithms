// Problem: Profit Maximisation
// Approach:
// Max Heap (Priority Queue)
// Description:
// Given N rows of seats and A customers,
// each customer buys a ticket from the row
// having the maximum available seats.
// After selling one ticket, the seat count
// of that row decreases by 1.
// Find the maximum profit.
// Time Complexity:
// O(A log N)
// Space Complexity:
// O(N)
class Solution {
public:
    int solve(vector<int>& A, int B) {
        // Your code here
        priority_queue<int>pq(A.begin(),A.end());
        int ans=0;
        while(B){
            int Max=pq.top();
            pq.pop();
            ans+=Max;
            pq.push(Max-1);
            B--;
        }
        return ans;
    }
};
