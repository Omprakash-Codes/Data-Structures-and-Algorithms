/*
Problem: Check Palindrome Using Recursion
Category: Recursion / Strings

Problem Statement:
Check whether a given string is a palindrome using recursion.

Approach:
1. Compare first and last characters.
2. If they are equal, move towards the middle.
3. Repeat the process recursively.
4. If all characters match, string is palindrome.

Time Complexity:
- O(n)

Space Complexity:
- O(n) (Call Stack)
*/

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int start, int end) {
    if(start >= end) return true;
    
    if(s[start] != s[end]) return false;
    
    return isPalindrome(s, start + 1, end - 1);
}

int main() {
    string s = "madam";
    cout << isPalindrome(s, 0, s.length() - 1);
    return 0;
}
