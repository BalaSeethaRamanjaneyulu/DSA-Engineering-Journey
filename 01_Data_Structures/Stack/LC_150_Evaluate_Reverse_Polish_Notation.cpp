/**
 * @file LC_150_Evaluate_Reverse_Polish_Notation.cpp
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 150: Evaluate Reverse Polish Notation
 *
 * Problem: Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * Valid operators are +, -, *, and /. Each operand may be an integer or another expression.
 *
 * Platform: LeetCode #150
 * Approach: Stack-based Evaluation
 * Time:     O(N)
 * Space:    O(N)
 * Link:     https://leetcode.com/problems/evaluate-reverse-polish-notation/
 */

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_set>

using namespace std;

class Solution {
public:
    /**
     * @brief Evaluates an RPN expression.
     * 
     * @param tokens A list of strings representing the expression.
     * @return int The result of the evaluation.
     */
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_set<string> operators = {"+", "-", "*", "/"};

        for (const string& token : tokens) {
            if (operators.find(token) != operators.end()) {
                // Pop the top two operands
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();

                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else if (token == "/") st.push(a / b); // C++ division truncates toward zero by default
            } else {
                // Token is an operand, push to stack
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};

// ─── Driver ──────────────────────────────────────────────────────────────────
int main() {
    Solution sol;
    
    // Test Case: ["2","1","+","3","*"] -> (2 + 1) * 3 = 9
    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
    cout << "Test 1 result: " << sol.evalRPN(tokens1) << " (Expected: 9)" << endl;

    // Test Case: ["10","6","9","3","+","-11","*","/","*","17","+","5","+"] -> 22
    vector<string> tokens2 = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << "Test 2 result: " << sol.evalRPN(tokens2) << " (Expected: 22)" << endl;

    return 0;
}
