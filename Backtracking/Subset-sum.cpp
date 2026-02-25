// Problem: Subset Sum Problem
// Approach: Recursion (Pick / Not Pick Technique)
// Description:
// Generate all possible subset sums from the given array using recursion.
// At each index, we have two choices:
// 1. Include the current element in subset
// 2. Exclude the current element from subset
// Time Complexity: O(2^N)
// Function to generate all possible subset sums using recursion
// Time Complexity: O(2^n) because each element has 2 choices (pick / not pick)

void subsetSum(int index, int sum, vector<int> &arr, int N, vector<int> &result)
{
    // Base case: if we reach the end of array
    if(index == N)
    {
        result.push_back(sum); // store current subset sum
        return;
    }

    // Pick the current element
    subsetSum(index + 1, sum + arr[index], arr, N, result);

    // Do not pick the current element
    subsetSum(index + 1, sum, arr, N, result);
}

vector<int> subsetSums(vector<int> arr, int N)
{
    vector<int> result;
    subsetSum(0, 0, arr, N, result);
    sort(result.begin(), result.end()); // sort all subset sums
    return result;
}
