// Problem: Permutations
// Approach: Backtracking
// Description:
// Generate all possible permutations of the given array.
// We pick elements one by one and mark them as used.
// After exploring a permutation, we backtrack by unmarking the element.
//
// Time Complexity: O(N!)
// Space Complexity: O(N)
class Solution {
public:
	void permutation(vector<int>& nums,int index,int n,vector<vector<int>>&ans){
		//base case
		if(index==n-1){
			ans.push_back(nums);
			return;
		}	
		for(int i=index;i<n;i++){
			swap(nums[index],nums[i]);
			permutation(nums,index+1,n,ans);
			swap(nums[index],nums[i]);
		}
	}
    vector<vector<int>> permute(vector<int>& nums) {
        // Code here
		vector<vector<int>>ans;
		permutation(nums,0,nums.size(),ans);
		return ans;
    }
};
