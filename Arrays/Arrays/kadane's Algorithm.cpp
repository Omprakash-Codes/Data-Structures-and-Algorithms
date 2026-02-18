/*
Algorithm: Kadane’s Algorithm
Category: Array / Dynamic Programming
Problem Type: Maximum Subarray Sum

Approach:
Kadane’s Algorithm is used to find the maximum sum of a 
contiguous subarray in linear time.

How It Works:
1. Initialize two variables:
   - currentSum = 0
   - maxSum = INT_MIN
2. Traverse the array.
3. Add current element to currentSum.
4. Update maxSum = max(maxSum, currentSum).
5. If currentSum becomes negative, reset it to 0.
6. Continue until the end of the array.

Key Idea:
If the running sum becomes negative, it will not contribute 
to the maximum subarray, so we discard it.

Time Complexity:
- O(n)

Space Complexity:
- O(1)

Stable: Not Applicable
Adaptive: Not Applicable

Use Case:
Used in problems involving:
- Maximum Subarray Sum
- Stock Buy and Sell (variation)
- Dynamic Programming optimization
*/
int maxSubarraySum(vector<int> &arr) {
    // Your code here
	int n=arr.size();
	int ans=INT_MIN;
	int sum=0;
	for(int i=0;i<n;i++){
		if(sum<0){
		  sum=arr[i];
		}else{	
		sum+=arr[i];
		}
		ans=max(ans,sum);
		
	}
    return ans;
}
