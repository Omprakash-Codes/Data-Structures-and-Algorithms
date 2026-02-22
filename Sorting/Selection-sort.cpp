/*
Algorithm: Selection Sort
Category: Sorting Algorithm
Approach: Repeatedly find the minimum element from the unsorted part 
          and place it at the beginning.

How It Works:
1. Divide the array into sorted and unsorted parts.
2. Initially, the sorted part is empty.
3. Find the minimum element in the unsorted part.
4. Swap it with the first element of the unsorted part.
5. Move the boundary of the sorted part one step forward.
6. Repeat until the entire array is sorted.

Time Complexity:
- Best Case: O(n²)
- Average Case: O(n²)
- Worst Case: O(n²)

Space Complexity:
- O(1) (In-place sorting)

Stable: No
Adaptive: No

Use Case:
Suitable for small datasets or when memory writes are costly.
*/

class Solution {
public:
  vector<int> selectionSort(vector<int>& arr) {
    // Write your code here
	int n=arr.size();
	for(int i=0;i<n;i++){
	int index=i;
	for(int j=i+1;j<n;j++){
		if(arr[j]<arr[index]){
			index=j;
		}
	}
	swap(arr[i],arr[index]);
	}
	return arr;
  }
};
