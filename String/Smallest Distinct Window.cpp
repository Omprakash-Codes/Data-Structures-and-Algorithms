/*
Problem: Smallest Distinct Window in a String
Category: Strings / Sliding Window / Hashing

Problem Statement:
Given a string, find the length of the smallest substring 
that contains all the distinct characters of the original string.

Approach:
1. Count the number of distinct characters in the string.
2. Use sliding window technique with two pointers (left and right).
3. Expand the window by moving the right pointer 
   and maintain frequency of characters.
4. When current window contains all distinct characters,
   try to shrink the window from the left.
5. Update the minimum window length during this process.

Key Idea:
Maintain a valid window that contains all unique characters 
and minimize its size using two pointers.

Time Complexity:
- O(n)

Space Complexity:
- O(256)  (For character frequency storage)

Use Case:
Used in problems involving:
- Minimum Window Substring
- String Optimization
- Sliding Window Technique
*/
int findSubString(string str) {
    // Your code here
	int n=str.size(),uniquechar=0;
	int freq[256]={0};
	//first we find the how many uniquechar are present in given string
	for(int i=0;i<n;i++){
		if(freq[str[i]]==0){
			freq[str[i]]++;
			uniquechar++;
		}
	}
	//sliding window lagayenge
	int start=0,end=0,ans=n,currentwindowuniquechar=0;
	int count[256]={0};
	while(end<n){
		count[str[end]]++;
		if(count[str[end]]==1){
			currentwindowuniquechar++;
		}
		end++;
		//ab window ko chota karenge jab tak sare element present ho us window me aur check karenge ki sare element present hai current window me
		while(currentwindowuniquechar==uniquechar){
			ans=min(ans,end-start);
			count[str[start]]--;
			if(count[str[start]]==0){
				currentwindowuniquechar--;
			}
			start++;
		}
	}
	return ans;
}
