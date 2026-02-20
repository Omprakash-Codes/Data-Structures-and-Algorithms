/*
Problem: Power of a Number
Category: Recursion

Problem Statement:
Find x raised to the power n using recursion.

Approach:
1. Base Case:
   - If n == 0 return 1
2. Recursive Case:
   - Return x * power(x, n-1)

Time Complexity:
- O(n)

Space Complexity:
- O(n) (Call Stack)
*/

#include <bits/stdc++.h>
using namespace std;

int power(int x, int n) {
    if(n == 0) return 1;
    
    return x * power(x, n - 1);
}

int main() {
    int x = 2, n = 3;
    cout << power(x, n);
    return 0;
}
