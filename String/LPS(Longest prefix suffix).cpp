/*
Problem: Longest Prefix Suffix (LPS)
Category: Strings / Pattern Matching

Problem Statement:
Given a string, find the length of the longest proper prefix 
which is also a suffix of the string.

Note:
Prefix and suffix should not be equal to the entire string.

Approach:
1. Use LPS (Longest Prefix Suffix) array technique.
2. Initialize an array lps[] of same length as the string.
3. Traverse the string and compare characters.
4. If characters match:
   - Increase the length of current prefix.
   - Assign it to lps[i].
5. If mismatch occurs:
   - Move to previous LPS value.
6. Continue until end of string.

Key Idea:
Reuse previously computed prefix information 
to avoid redundant comparisons.

Time Complexity:
- O(n)

Space Complexity:
- O(n)

Use Case:
- Used in KMP Algorithm
- Pattern Matching Problems
- String Repetition Detection
*/
int getLPSLength(string& s) {
    // Your code here
	int n=s.size();
	vector<int>lps(n,0);
	int prefix=0,sufix=1;
	while(sufix<n){
		if(s[prefix]==s[sufix]){
			lps[sufix]=prefix+1;
			prefix++,sufix++;
		}else{
			if(prefix==0){
				sufix++;
			}else{
				prefix=lps[prefix-1];
			}
		}
	}
	return lps[n-1];
}
