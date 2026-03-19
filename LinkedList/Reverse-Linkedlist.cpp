// Problem: Reverse a Linked List
// Approach: Iterative (Using Three Pointers)
// Description:
// Reverse the given linked list by changing the direction of pointers.
// We maintain three pointers:
// 1. prev -> points to previous node
// 2. curr -> current node
// 3. next -> stores next node
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

// Function to reverse linked list
Node* reverseList(Node* head)
{
    Node* prev = NULL;   // Initially previous is NULL
    Node* curr = head;   // Start from head

    while(curr != NULL)
    {
        Node* nextNode = curr->next; // Store next node

        curr->next = prev; // Reverse the link

        prev = curr;       // Move prev forward
        curr = nextNode;   // Move curr forward
    }

    // prev becomes new head
    return prev;
}
