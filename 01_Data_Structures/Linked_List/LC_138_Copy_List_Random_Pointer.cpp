/**
 * @file LC_138_Copy_List_Random_Pointer.cpp
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 138: Copy List with Random Pointer
 *
 * Problem: A linked list of length n is given such that each node contains an additional random pointer, 
 * which could point to any node in the list, or null. Construct a deep copy.
 *
 * Platform: LeetCode #138
 * Approach: Node Interweaving (Three-Pass Optimization)
 * Time:     O(N)
 * Space:    O(1) (excluding the new list)
 * Link:     https://leetcode.com/problems/copy-list-with-random-pointer/
 */

#include <iostream>

using namespace std;

/**
 * Definition for a Node.
 */
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    /**
     * @brief Creates a deep copy of a list with random pointers using interweaving.
     * 1. Create copy nodes and insert them between original nodes.
     * 2. Set the random pointers for the copy nodes.
     * 3. Separate the original and copy nodes into two distinct lists.
     * 
     * @param head The head of the original list.
     * @return Node* The head of the deep-copied list.
     */
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        // Step 1: Interweave Copy Nodes
        // Original: A -> B -> C
        // Interweaved: A -> A' -> B -> B' -> C -> C'
        Node* curr = head;
        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }
        
        // Step 2: Set Random Pointers
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        
        // Step 3: Separate Lists
        curr = head;
        Node* copyHead = head->next;
        Node* tempCopy = copyHead;
        
        while (curr) {
            curr->next = curr->next->next;
            if (tempCopy->next) {
                tempCopy->next = tempCopy->next->next;
            }
            
            curr = curr->next;
            tempCopy = tempCopy->next;
        }
        
        return copyHead;
    }
};

// ─── Driver ──────────────────────────────────────────────────────────────────
int main() {
    Solution sol;

    // Create Sample List: [[7,null],[13,0],[11,4],[10,2],[1,0]]
    Node* n1 = new Node(7);
    Node* n2 = new Node(13);
    Node* n3 = new Node(11);
    Node* n4 = new Node(10);
    Node* n5 = new Node(1);

    n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n5;
    n2->random = n1; n3->random = n5; n4->random = n3; n5->random = n1;

    Node* copy = sol.copyRandomList(n1);
    
    cout << "Original first node val: " << n1->val << endl;
    cout << "Copied first node val:   " << copy->val << endl;
    cout << "Copied node 2 random points to val: " << copy->next->random->val << endl;

    return 0;
}
