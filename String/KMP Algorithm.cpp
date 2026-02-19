/*
Algorithm: KMP (Knuth-Morris-Pratt) String Matching
Category: Strings / Pattern Matching

Problem Statement:
Given a text and a pattern, find all occurrences of 
the pattern in the text efficiently.

Approach:
KMP Algorithm avoids unnecessary comparisons by using 
information from previously matched characters.

It uses an auxiliary array called:
LPS (Longest Prefix Suffix)

LPS Array:
LPS[i] stores the length of the longest proper prefix 
which is also a suffix for the substring pattern[0...i].

Steps:
1. Preprocess the pattern to build the LPS array.
2. Compare characters of text and pattern.
3. On mismatch:
   - Use LPS to skip unnecessary comparisons.
4. On match:
   - Move both pointers forward.
5. Repeat until pattern is found or text ends.

Key Idea:
Do not restart matching from the beginning 
after mismatch. Use LPS array to continue matching.

Time Complexity:
- Preprocessing (LPS): O(m)
- Pattern Matching: O(n)
- Overall: O(n + m)

Space Complexity:
- O(m)  (For LPS array)

Use Case:
Efficient pattern searching in:
- Text Editors
- DNA Sequence Matching
- Plagiarism Detection
*/
vector<int> search(string &pat, string &txt) {
    // Your code here
	vector<int>ans;
	//calculate the lps of pat
	vector<int>lps(pat.size(),0);
	int pre=0,suf=1;
	while(suf<pat.size()){
		if(pat[pre]==pat[suf]){
			lps[suf]=pre+1;
			pre++,suf++;
		}else{
			if(pre==0){
				suf++;
			}else{
				pre=lps[pre-1];
			}
		}
	}
	//match the pat in txt
	pre=0,suf=0;
	while(suf<txt.size()){
		if(pat[pre]==txt[suf]){
			pre++,suf++;
			if(pre==pat.size()){
				ans.push_back(suf-pre);
				pre=lps[pre-1];
			}
		}else{
			if(pre==0){
				suf++;
			}else{
				pre=lps[pre-1];
			}
		}
	}
    return ans;
}
