/**
 * @file LC_206_Reverse_Linked_List.cpp
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 206: Reverse Linked List
 *
 * Problem: Given the head of a singly linked list, reverse the list, 
 *          and return the reversed list.
 *
 * Platform: LeetCode #206
 * Approach: Iterative (Three Pointers)
 * Time:     O(N)  — Single pass through the list.
 * Space:    O(1)  — In-place reversal using three pointers.
 * Link:     https://leetcode.com/problems/reverse-linked-list/
 */

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list node.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    /**
     * @brief Reverses a singly linked list iteratively.
     *
     * We maintain three pointers:
     * - prev: points to the previous node (initially null)
     * - curr: points to the current node (initially head)
     * - next: temporary pointer to the next node
     *
     * @param head Pointer to the head of the list.
     * @return ListNode* Pointer to the new head of the reversed list.
     */
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        
        while (curr != nullptr) {
            ListNode *next_temp = curr->next; // Temporarily store next
            curr->next = prev;              // Reverse the link
            prev = curr;                    // Move prev forward
            curr = next_temp;               // Move curr forward
        }
        
        return prev; // New head is prev
    }
};

// ─── Driver ──────────────────────────────────────────────────────────────────
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Test Case: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    cout << "Original List: ";
    printList(head);

    ListNode *reversedHead = sol.reverseList(head);

    cout << "Reversed List: ";
    printList(reversedHead);

    return 0;
}
