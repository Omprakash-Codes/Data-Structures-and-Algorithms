/*
Algorithm: Bubble Sort
Category: Sorting Algorithm
Approach: Repeatedly compare adjacent elements and swap them 
          if they are in the wrong order.

How It Works:
1. Traverse the array from beginning to end.
2. Compare adjacent elements.
3. Swap them if they are in the wrong order.
4. After each pass, the largest element moves to its correct position.
5. Repeat the process for remaining unsorted elements.

Time Complexity:
- Best Case: O(n)        (Already Sorted)
- Average Case: O(n²)
- Worst Case: O(n²)

Space Complexity:
- O(1) (In-place sorting)

Stable: Yes
Adaptive: Yes

Use Case:
Simple implementation, useful for small datasets or when 
the array is nearly sorted.
*/
class Solution {
public:
  vector<int> bubbleSort(vector<int>& arr) {
    // Write your code here
	int n=arr.size();
	for(int j=0;j<n-1;j++){
		bool sp=false;
	for(int i=0;i<n-1-j;i++){
		if(arr[i]>arr[i+1]){
			sp=true;
			swap(arr[i],arr[i+1]);
		}
	}
	if(sp==false){
		return arr;
	}
	}
	return arr;
  }
};
