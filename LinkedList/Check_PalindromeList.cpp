// Problem: Check if Linked List is Palindrome
// Approach: Slow-Fast Pointer + Reverse Second Half
// Description:
// 1. Find the middle of the linked list using slow and fast pointers.
// 2. Reverse the second half of the list.
// 3. Compare first half and second half.
// 4. If all elements match, it is a palindrome.
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
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL)
    {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

// Function to check palindrome
bool isPalindrome(Node* head)
{
    if(head == NULL || head->next == NULL)
        return true;

    // Step 1: Find middle
    Node* slow = head;
    Node* fast = head;

    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse second half
    Node* secondHalf = reverseList(slow->next);

    // Step 3: Compare both halves
    Node* firstHalf = head;

    while(secondHalf != NULL)
    {
        if(firstHalf->data != secondHalf->data)
            return false;

        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}
