// Problem: Find Middle of Linked List
// Approach: Slow and Fast Pointer Technique
// Description:
// Use two pointers:
// 1. slow -> moves one step at a time
// 2. fast -> moves two steps at a time
//
// When fast reaches the end, slow will be at the middle.
//
// Time Complexity: O(N)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

// Structure of Node
struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Function to find middle node
Node* findMiddle(Node* head)
{
    // Edge case
    if(head == NULL)
        return NULL;

    Node* slow = head; // moves 1 step
    Node* fast = head; // moves 2 steps

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;         // move slow by 1
        fast = fast->next->next;   // move fast by 2
    }

    // slow will be at middle
    return slow;
}
