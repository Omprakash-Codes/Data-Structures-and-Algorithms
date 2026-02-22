/*
Algorithm: Insertion Sort
Category: Sorting Algorithm
Approach: Build the sorted array one element at a time 
          by inserting elements into their correct position.

How It Works:
1. Start from the second element of the array.
2. Compare it with elements before it.
3. Shift larger elements one position ahead.
4. Insert the current element into its correct position.
5. Repeat for all elements in the array.

Time Complexity:
- Best Case: O(n)        (Already Sorted)
- Average Case: O(n²)
- Worst Case: O(n²)

Space Complexity:
- O(1) (In-place sorting)

Stable: Yes
Adaptive: Yes

Use Case:
Efficient for small datasets or nearly sorted arrays.
*/
class Solution {
public:
  vector<int> insertionSort(vector<int>& arr) {
    // Write your code here
	int n=arr.size();
	for(int j=1;j<n;j++){
		for(int i=j;i>0;i--){
			if(arr[i]<arr[i-1]){
				swap(arr[i],arr[i-1]);
			}else{
				break;
			}
		}
	}
	return arr;
  }
};
