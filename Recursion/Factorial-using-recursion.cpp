/*
Problem: Factorial Using Recursion
Category: Recursion

Problem Statement:
Find the factorial of a number using recursion.

Approach:
1. Base Case:
   - If n == 0 or n == 1 return 1
2. Recursive Case:
   - Return n * factorial(n-1)

Time Complexity:
- O(n)

Space Complexity:
- O(n) (Call Stack)
*/

#include <bits/stdc++.h>
using namespace std;

int factorial(int n) {
    if(n == 1) return 1;
    
    return n * factorial(n - 1);
}

int main() {
    int n = 5;
    cout << factorial(n);
    return 0;
}
