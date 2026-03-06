// Problem: Combination Sum
// Approach: Recursion + Backtracking
// Description:
// Find all unique combinations of elements that sum up to the target value.
// Each element can be used multiple times.
//
// At every index we have two choices:
// 1. Pick the element (stay at same index because element can be reused)
// 2. Skip the element and move to next index
//
// Time Complexity: Exponential
// Space Complexity: O(N) recursion stack
void find(vector<int>&candidates,int index,int n,int target,vector<int>&temp,vector<vector<int>>&ans){
	//base case
	if(target==0){
		ans.push_back(temp);
		return;
	}
	if(target<0 || index==n){
		return;
	}
	vector<int>used(51,0);
	for(int i=index;i<n;i++){
		if(!used[candidates[i]]){
			used[candidates[i]]=1;
			temp.push_back(candidates[i]);
			find(candidates,i+1,n,target-candidates[i],temp,ans);
			temp.pop_back();
		}
	}
	

}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	sort(candidates.begin(),candidates.end());
	vector<int>temp;
	vector<vector<int>>ans;
    find(candidates,0,candidates.size(),target,temp,ans);
	return ans;
}
