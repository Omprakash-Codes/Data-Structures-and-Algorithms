/*
Algorithm: Merge Sort
Category: Recursion / Divide and Conquer

Problem Statement:
Sort an array using Merge Sort algorithm.

Approach:
Merge Sort follows Divide and Conquer technique:

1. Divide:
   - Divide the array into two halves.

2. Conquer:
   - Recursively sort both halves.

3. Combine:
   - Merge the two sorted halves into one sorted array.

Time Complexity:
- Best Case: O(n log n)
- Average Case: O(n log n)
- Worst Case: O(n log n)

Space Complexity:
- O(n) (Temporary array for merging)

Stable: Yes

Use Case:
Efficient sorting for large datasets 
and used in external sorting.
*/

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;
    
    int left = low;
    int right = mid + 1;
    
    while(left <= mid && right <= high) {
        if(arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }
    
    while(left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    
    while(right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    
    for(int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high) {
    if(low >= high) return;
    
    int mid = (low + high) / 2;
    
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    
    merge(arr, low, mid, high);
}

int main() {
    vector<int> arr = {5, 2, 4, 1, 3};
    
    mergeSort(arr, 0, arr.size() - 1);
    
    for(int i : arr) {
        cout << i << " ";
    }
    
    return 0;
}
