/*
Problem: Fibonacci Series Using Recursion
Category: Recursion

Problem Statement:
Find the nth Fibonacci number using recursion.

Approach:
1. Base Case:
   - If n == 0 return 0
   - If n == 1 return 1
2. Recursive Case:
   - Return fibonacci(n-1) + fibonacci(n-2)

Time Complexity:
- O(2^n)

Space Complexity:
- O(n) (Call Stack)
*/

#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n) {
    if(n <= 1){
      return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 6;
    cout << fibonacci(n);
    return 0;
}
