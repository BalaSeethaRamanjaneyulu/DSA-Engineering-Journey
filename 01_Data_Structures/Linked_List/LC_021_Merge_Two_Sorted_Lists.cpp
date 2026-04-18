/**
 * @file LC_021_Merge_Two_Sorted_Lists.cpp
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 021: Merge Two Sorted Lists
 *
 * Problem: Merge two sorted linked lists and return it as a sorted list.
 *
 * Platform: LeetCode #021
 * Approach: Iterative with Dummy Node
 * Time:     O(M + N)
 * Space:    O(1)
 * Link:     https://leetcode.com/problems/merge-two-sorted-lists/
 */

#include <iostream>
#include <vector>

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
     * @brief Merges two sorted lists into one sorted list.
     *
     * We use a dummy node to simplify the logic for the head of the new list.
     *
     * @param list1 Pointer to the first sorted list.
     * @param list2 Pointer to the second sorted list.
     * @return ListNode* Pointer to the head of the merged list.
     */
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node as the starting point
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        
        // Attach the remaining part of the non-empty list
        tail->next = (list1 != nullptr) ? list1 : list2;
        
        return dummy.next;
    }
};

// ─── Driver & Utilities ──────────────────────────────────────────────────────
void printList(ListNode* head) {
    while (head) {
        cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    cout << endl;
}

ListNode* createList(const vector<int>& nums) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int num : nums) {
        tail->next = new ListNode(num);
        tail = tail->next;
    }
    return dummy.next;
}

int main() {
    Solution sol;

    // Test Case: [1,2,4] and [1,3,4]
    ListNode* l1 = createList({1, 2, 4});
    ListNode* l2 = createList({1, 3, 4});

    cout << "List 1: "; printList(l1);
    cout << "List 2: "; printList(l2);

    ListNode* merged = sol.mergeTwoLists(l1, l2);
    cout << "Merged: "; printList(merged);

    return 0;
}
