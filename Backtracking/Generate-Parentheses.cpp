// Problem: Generate Parentheses
// Approach: Backtracking
// Description:
// Generate all valid combinations of n pairs of parentheses.
// We maintain two counters:
// 1. open  -> number of '(' used
// 2. close -> number of ')' used
//
// Rules:
// - We can add '(' if open < n
// - We can add ')' if close < open
//
// Time Complexity: O(2^N)
// Space Complexity: O(N)
void genparen(int left,int right,string &temp,vector<string>&ans){
	//base case
	if(left>right||left<0){
		return;
	}
	if(left==0&&right==0){
		ans.push_back(temp);
		return;
	}

	//pahle open bracket ko push karenge
	temp.push_back('(');
	genparen(left-1,right,temp,ans);
	temp.pop_back();
	//ab close bracket ko push karenge
	temp.push_back(')');
	genparen(left,right-1,temp,ans);
	temp.pop_back();
}
vector<string> generateParenthesis(int n) {
    vector<string>ans;
	string temp;
	genparen(n,n,temp,ans);
	return ans;
}
