// Problem: First Negative Number in Every Window of Size K
// Approach: Sliding Window + Queue
// Description:
// Given an array and window size k, find the first negative number
// in every window of size k. If no negative exists, return 0.
// Use a queue to store indices of negative elements.
// Time Complexity: O(N)
// Space Complexity: O(K)
vector<int> firstNegativeWindow(vector<int>& arr, int k) {
    vector<int>ans;
    queue<int>q;
    for(int i=0;i<k-1;i++){
        if(arr[i]<0){
            q.push(i);
        }
    }
    for(int i=k-1;i<arr.size();i++){
        //agar negative hua to push kar denge use index ko
        if(arr[i]<0){
            q.push(i);
        }
     //ab check karenge ki kya hamare window exced kiya to nhi hai hamre k size se agar kiya hai to hata do 
        if(!q.empty()&&q.front()<=i-k){
            q.pop();
        }
        //agar queue not empty hua to uske front ko push kar denge answer me
        if(!q.empty()){
            ans.push_back(arr[q.front()]);
        }else{
            ans.push_back(0);
        }
    }
    return ans;
}
