//You are given an integer array nums. Your task is to return an array answer where each element 
//answer[i] represents the product of all elements in nums except nums[i].
//You must solve this problem without using the division operation, 
//and your algorithm must run in O(n) time complexity
vector<int> productExceptSelf(vector<int>& nums) {
    // code here
    int n=nums.size();
    vector<int>ans(n);
    if(n==0){
        return ans;
    }
    vector<int>prefixproduct(n);
    prefixproduct[0]=1;
    for(int i=1;i<n;i++){
        prefixproduct[i]=prefixproduct[i-1]*nums[i-1];
    }
    vector<int>suffixproduct(n);
    suffixproduct[n-1]=1;
    for(int i=n-2;i>=0;i--){
        suffixproduct[i]=suffixproduct[i+1]*nums[i+1];
    }
    for(int i=0;i<n;i++){
        ans[i]=prefixproduct[i]*suffixproduct[i];
    }
    return ans;
}
