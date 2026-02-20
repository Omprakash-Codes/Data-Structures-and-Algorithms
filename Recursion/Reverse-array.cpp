/*
Problem: Reverse Array Using Recursion
Category: Recursion / Arrays

Problem Statement:
Reverse an array using recursion.

Approach:
1. Swap first and last elements.
2. Move towards the middle.
3. Repeat recursively until start >= end.

Time Complexity:
- O(n)

Space Complexity:
- O(n) (Call Stack)
*/

#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr, int start, int end) {
    if(start >= end) return;
    
    swap(arr[start], arr[end]);
    
    reverseArray(arr, start + 1, end - 1);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    
    reverseArray(arr, 0, arr.size() - 1);
    
    for(int i : arr) {
        cout << i << " ";
    }
    
    return 0;
}
