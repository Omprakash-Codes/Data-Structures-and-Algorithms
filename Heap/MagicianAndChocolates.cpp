// Problem: Magician and Chocolates
// Approach:
// Max Heap (Priority Queue)
// Description:
// A magician has bags containing chocolates.
// Every minute, he eats chocolates from the
// bag with the maximum chocolates. After eating,
// that bag is refilled with floor(chocolates/2).
// Find the maximum chocolates eaten in A minutes.
// Time Complexity:
// O(A log N)
// Space Complexity:
// O(N)
class Solution {
public:
    int nchoc(int A, vector<int> &B) {
        // Your code here
        priority_queue<int>pq(B.begin(),B.end());
        long long ans=0;
        while(A && pq.size()){
            ans+=pq.top();
            if(pq.top()/2){
             pq.push(pq.top()/2);
            } 
            pq.pop();
            A--;
        }
        return ans%1000000007;
    }
};
