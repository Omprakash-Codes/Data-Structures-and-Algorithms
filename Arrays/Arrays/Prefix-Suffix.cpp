/*
Concept: Prefix and Suffix Arrays
Category: Array / Preprocessing Technique

Definition:
Prefix array stores cumulative result from start to current index.
Suffix array stores cumulative result from end to current index.

Common Types:
1. Prefix Sum
2. Prefix Maximum / Minimum
3. Suffix Sum
4. Suffix Maximum / Minimum

How It Works (Prefix Sum Example):
1. Create a prefix array of same size as original array.
2. prefix[0] = arr[0]
3. For i from 1 to n-1:
      prefix[i] = prefix[i-1] + arr[i]
4. Now any subarray sum from L to R can be found as:
      prefix[R] - prefix[L-1]

How It Works (Suffix Example):
1. suffix[n-1] = arr[n-1]
2. For i from n-2 to 0:
      suffix[i] = suffix[i+1] + arr[i]

Key Idea:
Precompute values once to answer range queries in O(1).

Time Complexity:
- Precomputation: O(n)
- Query: O(1)

Space Complexity:
- O(n)

Use Case:
- Range Sum Queries
- Subarray Problems
- Equilibrium Index
- Product of Array Except Self
*/
