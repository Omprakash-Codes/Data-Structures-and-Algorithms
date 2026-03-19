// Problem: Split Linked List into Two Halves
// Approach: Slow and Fast Pointer Technique
// Description:
// Divide the linked list into two halves.
// Use slow and fast pointers to find the middle.
// First half: head to middle
// Second half: middle+1 to end
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

// Function to split linked list into two halves
void splitList(Node* head, Node* &firstHalf, Node* &secondHalf)
{
    // Edge case
    if(head == NULL)
    {
        firstHalf = NULL;
        secondHalf = NULL;
        return;
    }

    Node* slow = head;
    Node* fast = head;

    // Find middle using slow-fast pointer
    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // First half starts from head
    firstHalf = head;

    // Second half starts from next of middle
    secondHalf = slow->next;

    // Break the link
    slow->next = NULL;
}
