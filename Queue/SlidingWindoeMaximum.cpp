// Problem: Sliding Window Maximum
// Approach: Deque (Monotonic Queue)
// Description:
// Given an array and window size k,
// find the maximum element in every window of size k.
// Use deque to store indices of useful elements.
// Maintain elements in decreasing order inside deque.
// Time Complexity: O(N)
// Space Complexity: O(K)
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
     vector<int>ans;
     deque<int>d;
     //deque me pahle k-1 element ko dal denge
     for(int i=0;i<k-1;i++){
        while(!d.empty()&&nums[d.back()]<nums[i]){
            d.pop_back();
        }
        d.push_back(i);
     }
     //then main operation start karenge
     for(int i=k-1;i<nums.size();i++){
        while(!d.empty()&&nums[d.back()]<nums[i]){
            d.pop_back();
        }
        d.push_back(i);
        //window ka length check karenge agar jada hoga to pop kar denge
        if(!d.empty()&&d.front()<=i-k){
            d.pop_front();
        }
        //last me push karte jayenge front pe jo element hoga usko ans me
        ans.push_back(nums[d.front()]);
     }
     return ans;
}
