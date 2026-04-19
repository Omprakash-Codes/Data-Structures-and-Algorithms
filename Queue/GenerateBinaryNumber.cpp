// Problem: Generate Binary Numbers from 1 to N
// Approach: Queue (Level Order / BFS)
// Description:
// Generate binary representations of numbers from 1 to N.
// Use a queue to build binary numbers by appending '0' and '1'.
// Idea:
// Start with "1"
// For every number:
//   - Print current
//   - Push (current + "0")
//   - Push (current + "1")
// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    vector<string> generate(int n) {
        // Your code here
        vector<string>ans;
        queue<string>q;
        q.push("1");
        for(int i=0;i<n;i++){
            string temp=q.front();
            ans.push_back(q.front());
            q.pop();
            q.push(temp+'0');
            q.push(temp+'1');
        }  
        return ans;
    }
};
