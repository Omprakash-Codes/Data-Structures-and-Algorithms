/*
Algorithm: Binary Search
Category: Searching Algorithm
Approach: Divide and Conquer

Precondition:
- The array must be sorted.

How It Works:
1. Initialize two pointers: low = 0 and high = n - 1.
2. Find the middle index: mid = low + (high - low) / 2.
3. If the middle element equals the target, return its index.
4. If target is smaller than middle element, search in left half.
5. If target is greater than middle element, search in right half.
6. Repeat until low > high.

Time Complexity:
- Best Case: O(1)
- Average Case: O(log n)
- Worst Case: O(log n)

Space Complexity:
- O(1) (Iterative version)
- O(log n) (Recursive version due to call stack)

Stable: Not Applicable
Adaptive: No

Use Case:
Efficient searching in large sorted datasets.
*/
class Solution {
public:
    int search(vector<int>& arr, int target) {
        // Write your code here
		int n=arr.size();
		int start=0,end=n-1;
		while(start<=end){
			int mid=(start+end)/2;
			if(arr[mid]==target){
				return mid;
			}else if(arr[mid]>target){
				end=mid-1;
			}else{
				start=mid+1;
			}
		}
		return -1;
    }
};
