// Problem: Print All Subsets
// Approach: Recursion / Backtracking
// Description:
// Generate all possible subsets of a given array.
// At each index we have two choices:
// 1. Pick the current element
// 2. Do not pick the current element
//
// Time Complexity: O(2^N)
// Space Complexity: O(N) recursion stack
#include <bits/stdc++.h>
using namespace std;

// Recursive function to generate all subsets
void solve(int index, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans)
{
    // Base Case: If we reach end of array
    if(index == arr.size())
    {
        ans.push_back(ds); // store current subset
        return;
    }

    // Pick the current element
    ds.push_back(arr[index]);

    solve(index + 1, arr, ds, ans);

    // Backtrack: remove last element
    ds.pop_back();

    // Do not pick the current element
    solve(index + 1, arr, ds, ans);
}

vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> ans;
    vector<int> ds;

    // Start recursion from index 0
    solve(0, nums, ds, ans);

    return ans;
}
