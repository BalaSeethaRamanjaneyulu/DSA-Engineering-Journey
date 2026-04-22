/**
 * @file LC_155_Min_Stack.cpp
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 155: Min Stack
 *
 * Problem: Design a stack that supports push, pop, top, and retrieving 
 * the minimum element in constant time.
 *
 * Platform: LeetCode #155
 * Approach: Two Stacks (Data Stack + Min Stack)
 * Time:     O(1) for all operations
 * Space:    O(N)
 * Link:     https://leetcode.com/problems/min-stack/
 */

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

/**
 * @brief A stack that supports O(1) minimum retrieval.
 */
class MinStack {
private:
    stack<int> s;      // Main data stack
    stack<int> min_s;  // Auxiliary stack to track minimums

public:
    MinStack() {
    }
    
    /**
     * @brief Pushes element val onto stack.
     */
    void push(int val) {
        s.push(val);
        // If min stack is empty or val is new minimum, push to min stack
        if (min_s.empty() || val <= min_s.top()) {
            min_s.push(val);
        }
    }
    
    /**
     * @brief Removes the element on the top of the stack.
     */
    void pop() {
        // If the element being popped is the current minimum, pop from min stack too
        if (s.top() == min_s.top()) {
            min_s.pop();
        }
        s.pop();
    }
    
    /**
     * @brief Gets the top element of the stack.
     */
    int top() {
        return s.top();
    }
    
    /**
     * @brief Retrieves the minimum element in the stack.
     */
    int getMin() {
        return min_s.top();
    }
};

// ─── Driver ──────────────────────────────────────────────────────────────────
int main() {
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    
    cout << "Min after push -3: " << obj->getMin() << endl; // Should be -3
    
    obj->pop();
    cout << "Top after pop: " << obj->top() << endl;       // Should be 0
    cout << "Min after pop: " << obj->getMin() << endl;    // Should be -2
    
    delete obj;
    return 0;
}
