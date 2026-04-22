/**
 * @file LC_020_Valid_Parentheses.cpp
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 020: Valid Parentheses
 *
 * Problem: Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
 * determine if the input string is valid.
 *
 * Platform: LeetCode #020
 * Approach: Stack-based Balancing (LIFO)
 * Time:     O(N)
 * Space:    O(N)
 * Link:     https://leetcode.com/problems/valid-parentheses/
 */

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /**
     * @brief Checks if the input string of parentheses is balanced.
     * 
     * @param s The input string.
     * @return true if balanced, false otherwise.
     */
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> mapping = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (char c : s) {
            // If it's a closing bracket
            if (mapping.count(c)) {
                // Get the top element of the stack. If the stack is empty, set a dummy value.
                char topElement = st.empty() ? '#' : st.top();
                st.pop();

                // If the mapping for this closing bracket doesn't match the stack's top, it's invalid.
                if (topElement != mapping[c]) {
                    return false;
                }
            } else {
                // If it's an opening bracket, push it onto the stack.
                st.push(c);
            }
        }

        // If the stack is empty, all brackets were matched.
        return st.empty();
    }
};

// ─── Driver ──────────────────────────────────────────────────────────────────
int main() {
    Solution sol;
    string test1 = "()[]{}";
    string test2 = "([)]";
    string test3 = "{[]}";

    cout << "Test 1: " << (sol.isValid(test1) ? "Valid" : "Invalid") << endl;
    cout << "Test 2: " << (sol.isValid(test2) ? "Valid" : "Invalid") << endl;
    cout << "Test 3: " << (sol.isValid(test3) ? "Valid" : "Invalid") << endl;

    return 0;
}
