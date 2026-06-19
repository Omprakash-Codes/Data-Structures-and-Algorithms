// Problem: Take Gifts From the Richest Pile
// Approach:
// Max Heap (Priority Queue)
// Description:
// In each operation, choose the pile with the
// maximum gifts, take gifts leaving behind
// floor(sqrt(pile)), and repeat for k seconds.
// Return the total gifts remaining after k operations.
// Time Complexity:
// O((N + K) log N)
// Space Complexity:
// O(N)
long long pickGifts(vector<int>& gifts, int k) {
    long long ans=0;
    for(int i=0;i<gifts.size();i++){
        ans+=gifts[i];
    }
    priority_queue<int>pq(gifts.begin(),gifts.end());
    while(k){
        int rem=pq.top();
        pq.pop();
        ans-=rem-sqrt(rem);
        pq.push(sqrt(rem));
        k--;
    }
    return ans;
}
