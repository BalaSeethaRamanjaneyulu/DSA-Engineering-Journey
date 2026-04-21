/**
 * @file LC_023_Merge_k_Sorted_Lists.cpp
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 023: Merge k Sorted Lists
 *
 * Problem: You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
 * Merge all the linked-lists into one sorted linked-list and return it.
 *
 * Platform: LeetCode #023
 * Approach: Divide and Conquer (Merge Sort Style)
 * Time:     O(N log k) where N is total nodes, k is number of lists.
 * Space:    O(log k) due to recursion stack.
 * Link:     https://leetcode.com/problems/merge-k-sorted-lists/
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
};

class Solution {
public:
    /**
     * @brief Merges two sorted linked lists (standard helper).
     */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }

    /**
     * @brief Recursively divides the lists into halves and merges them.
     */
    ListNode* mergeKListsHelper(vector<ListNode*>& lists, int start, int end) {
        if (start > end) return nullptr;
        if (start == end) return lists[start];
        
        int mid = start + (end - start) / 2;
        ListNode* left = mergeKListsHelper(lists, start, mid);
        ListNode* right = mergeKListsHelper(lists, mid + 1, end);
        
        return mergeTwoLists(left, right);
    }

    /**
     * @brief Entry point for merging k lists.
     */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        return mergeKListsHelper(lists, 0, lists.size() - 1);
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
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < nums.size(); ++i) {
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    Solution sol;

    // Test Case: [[1,4,5],[1,3,4],[2,6]] -> [1,1,2,3,4,4,5,6]
    vector<ListNode*> lists;
    lists.push_back(createList({1, 4, 5}));
    lists.push_back(createList({1, 3, 4}));
    lists.push_back(createList({2, 6}));

    cout << "Lists to Merge: " << endl;
    for(auto l : lists) printList(l);

    ListNode* result = sol.mergeKLists(lists);
    cout << "Merged List: "; printList(result);

    return 0;
}
