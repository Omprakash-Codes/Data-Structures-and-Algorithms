/*
Problem: Longest Substring Without Repeating Characters
Category: Strings / Sliding Window

Problem Statement:
Given a string, find the length of the longest substring 
without repeating characters.

Approach:
1. Use two pointers (left and right) to maintain a sliding window.
2. Use a hash array/map to store the last index of each character.
3. Expand the window by moving the right pointer.
4. If a repeating character is found inside the window,
   move the left pointer to the right of its previous index.
5. Update the maximum length of substring at each step.

Key Idea:
Maintain a window of unique characters and 
adjust its size dynamically when repetition occurs.

Time Complexity:
- O(n)

Space Complexity:
- O(256)  (For character frequency storage)

Use Case:
Used in problems involving:
- Sliding Window Technique
- Unique character substring
- String optimization problems
*/
int maxUniqueSubstring(string& s) {
       //code here
	   int n=s.size();
	   vector<int>freq(256,0);
	   int start=0,end=0,ans=0;
	   
	   while(end<n){
		//repeating character ko window se hatana hai start ko ++ karke
		while(freq[s[end]]){
			freq[s[start]]=0;
			start++;
		}
		//agar is window me repeating character nhi hai to window ko expend karenge
		freq[s[end]]=1;
		end++;
		ans=max(ans,end-start);
	   }
	return ans;
}
