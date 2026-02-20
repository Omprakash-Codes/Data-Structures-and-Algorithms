/*
Problem: Print Numbers from 1 to N
Category: Recursion

Problem Statement:
Print numbers from 1 to N using recursion.

Approach:
1. Base Case:
   - If n == 0 return
2. Recursive Case:
   - Call function for n-1
   - Print n

Time Complexity:
- O(n)

Space Complexity:
- O(n) (Call Stack)
*/

#include <bits/stdc++.h>
using namespace std;

void printNumbers(int n) {
    if(n == 0) return;
    
    printNumbers(n - 1);
    cout << n << " ";
}

int main() {
    int n = 5;
    printNumbers(n);
    return 0;
}
