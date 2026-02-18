/*
Problem: Two Sum II - Input Array is Sorted
Concept: Two Pointer Approach
Approach: Use two pointers from start and end to find target sum
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;
    
    while(left < right) {
        int sum = numbers[left] + numbers[right];
        
        if(sum == target) {
            return {left + 1, right + 1};
        }
        else if(sum < target) {
            left++;
        }
        else {
            right--;
        }
    }
    
    return {-1, -1};
}

int main() {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    
    vector<int> result = twoSum(numbers, target);
    
    cout << "Indices: " << result[0] << " " << result[1];
    
    return 0;
}
