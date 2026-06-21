// Problem: Last Stone Weight
// Approach:
// Max Heap (Priority Queue)
// Description:
// Repeatedly take the two heaviest stones.
// If their weights are equal, both stones
// are destroyed. Otherwise, the remaining
// weight is inserted back into the heap.
// Time Complexity:
// O(N log N)
// Space Complexity:
// O(N)
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Your code here
        priority_queue<int>pq(stones.begin(),stones.end());
        while(pq.size()>1){
            int y=pq.top();
            pq.pop();
            int x=pq.top();
            pq.pop();
            if(y!=x){
                pq.push(y-x);
            }
        }
        if(!pq.empty()){
          return pq.top();
        }else{
            return 0;
        }  
    }
};
