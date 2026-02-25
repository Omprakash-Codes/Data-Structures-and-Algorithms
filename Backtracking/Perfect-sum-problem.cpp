// Problem: Perfect Sum Problem
// Approach: Recursion (Pick / Not Pick Technique)
// Description:
// Count the number of subsets whose sum equals the given target.
// At each index we have two choices:
// 1. Pick the element (if it does not exceed target)
// 2. Do not pick the element
// Time Complexity: O(2^N)
// Space Complexity: O(N) -> recursion stack
class Solution {
public:
	void find(vector<int>& arr,int index,int n,int &count,int sum,int target){
		if(sum==target){
			count++;
			return;
			}
		if(index==n||sum>target){
			return;
		}
		find(arr,index+1,n,count,sum+arr[index],target);
		find(arr,index+1,n,count,sum,target);
	}
    int countSubsetsWithSum(vector<int>& arr, int target) {
        // Your code here
		int count=0;
		find(arr,0,arr.size(),count,0,target);
		return count;
    }
};
