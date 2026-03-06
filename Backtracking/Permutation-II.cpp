// Problem: Permutations II
// Approach: Backtracking + Sorting
// Description:
// Generate all unique permutations of the given array which may contain duplicate elements.
// First sort the array so that duplicate elements come together.
// While generating permutations, skip duplicate elements that have already been used at the same recursion level.
//
// Time Complexity: O(N!)
// Space Complexity: O(N)
class Solution {
public:
	void uniquepermu(vector<int>&nums,int index,int n,vector<vector<int>>&ans){
		if(index==n-1){
			ans.push_back(nums);
			return;
		}
		vector<int>used(21,0);
		for(int i=index;i<n;i++){
			if(!used[nums[i]+10]){
			used[nums[i]+10]=1;	
			swap(nums[i],nums[index]);
			uniquepermu(nums,index+1,n,ans);
			swap(nums[i],nums[index]);
			}
		}
	}
    vector<vector<int>> permuteUnique(vector<int>&nums) {
        // Code here 
		vector<vector<int>>ans;
		uniquepermu(nums,0,nums.size(),ans);
		return ans;
    }
};
