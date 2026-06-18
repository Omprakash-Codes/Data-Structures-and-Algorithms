// Topic: Height of Heap
// Description:
// Calculate the height of a heap containing N nodes.
// Since a heap is a Complete Binary Tree,
// its height can be determined directly using
// the logarithmic relationship between the
// number of nodes and the tree height.
// Formula:
// Height = floor(log2(N))
// Time Complexity:
// O(1)
// Space Complexity:
// O(1)
class Solution {
public:
    int heapHeight(int N, int arr[]) {
        // Your code here
        if(N==1){
            return 1;
        }
        int height=0;
        while(N>1){
            N/=2;
            height++;
        }
        return height;
    }
};
