/*
Problem: Reverse Array
Approach: Two Pointer Technique
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;
    while(left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}
