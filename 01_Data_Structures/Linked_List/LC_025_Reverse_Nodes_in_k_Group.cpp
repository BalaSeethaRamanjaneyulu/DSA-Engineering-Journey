/**
 * @file LC_025_Reverse_Nodes_in_k_Group.cpp
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 025: Reverse Nodes in k-Group
 *
 * Problem: Given the head of a linked list, reverse the nodes of the list k at a time and return its modified head.
 * If the number of nodes is not a multiple of k left out nodes, in the end, should remain as it is.
 *
 * Platform: LeetCode #025 (Hard)
 * Approach: Recursive Group Reversal
 * Time:     O(N)
 * Space:    O(N/k) recursion stack
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;
        
        // Find the k-th node
        while (curr && count != k) {
            curr = curr->next;
            count++;
        }
        
        if (count == k) {
            // Reverse the sub-list starting from the (k+1)-th node
            curr = reverseKGroup(curr, k);
            
            // Reverse k nodes: head -> ... -> node_k
            while (count-- > 0) {
                ListNode* next_temp = head->next;
                head->next = curr;
                curr = head;
                head = next_temp;
            }
            head = curr;
        }
        return head;
    }
};

// ─── Driver ──────────────────────────────────────────────────────────────────
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
    ListNode* head = createList({1, 2, 3, 4, 5});
    cout << "Original: "; printList(head);
    
    head = sol.reverseKGroup(head, 2);
    cout << "k=2:      "; printList(head);
    
    return 0;
}
