/*
Problem: Sorting the Sentence
Category: Strings / Parsing

Problem Statement:
A sentence is given where each word contains a number at 
the end representing its position in the sorted sentence.
Rearrange the words in the correct order based on the 
numeric value attached to each word.

Approach:
1. Split the sentence into individual words.
2. Extract the last character of each word 
   (which represents its correct position).
3. Place the word at its corresponding index 
   in a result container.
4. Remove the numeric value from each word.
5. Join all words to form the sorted sentence.

Key Idea:
Use the digit at the end of each word as the 
correct position to rearrange the sentence.

Time Complexity:
- O(n)

Space Complexity:
- O(n)

Use Case:
Useful in problems involving string manipulation,
tokenization, and index-based rearrangement.
*/
class Solution {
public:
    string sortSentence(string s) {
        //Code here
		vector<string>position(10);
		string str=" ";
		for(int i=0;i<s.size();i++){
			if(s[i]>='0'&&s[i]<='9'){
				int index=s[i]-'0';
				position[index]=str;
				str.clear();
			}else{
				str.push_back(s[i]);
			}
		}
		string ans;
		for(int i=1;i<position[1].size();i++){
			ans.push_back(position[1][i]);
		}
		for(int i=2;i<10;i++){
			if(position[i].size()==0){
				break;
			}
			ans+=position[i];
		}
		return ans;
    }
};
