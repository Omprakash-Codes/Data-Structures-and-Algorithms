/*
Problem: Longest Palindrome That Can Be Built
Category: Strings / Greedy / Hashing

Problem Statement:
Given a string, find the length of the longest palindrome 
that can be built using its characters.

Approach:
1. Count the frequency of each character.
2. For each character:
   - If frequency is even, we can use all occurrences.
   - If frequency is odd, we can use (frequency - 1) characters.
3. At most one character with odd frequency can be placed 
   in the middle of the palindrome.
4. Add all even frequencies and one odd frequency (if exists).

Key Idea:
A palindrome has:
- Even count characters on both sides.
- Only one odd count character allowed in the center.

Time Complexity:
- O(n)

Space Complexity:
- O(1) (Using fixed-size frequency array)
*/
int longestPalindrome(string s) {
        vector<int>freq(256,0);
		for(int i=0;i<s.size();i++){
			freq[s[i]]++;
		}
		int ans=0;
		bool odd=false;
		for(int i=0;i<256;i++){
			if(freq[i]%2!=0){
				ans+=freq[i]-1;
				odd=true;
			}else{
				ans+=freq[i];
			}
		}
		if(odd){
			ans++;
		}
		return ans;
}
