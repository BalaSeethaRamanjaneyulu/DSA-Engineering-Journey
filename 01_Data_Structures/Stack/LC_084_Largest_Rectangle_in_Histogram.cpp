/**
 * @file LC_084_Largest_Rectangle_in_Histogram.cpp
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 084: Largest Rectangle in Histogram
 *
 * Problem: Given an array of integers heights representing the histogram's bar 
 * height where the width of each bar is 1, return the area of the largest rectangle.
 *
 * Platform: LeetCode #084
 * Approach: Monotonic Stack (Strictly Increasing)
 * Time:     O(N)
 * Space:    O(N)
 * Link:     https://leetcode.com/problems/largest-rectangle-in-histogram/
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @brief Finds the area of the largest rectangle in a histogram.
     * 
     * @param heights Vector of histogram bar heights.
     * @return int Maximum rectangle area.
     */
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st; // Stores indices
        int maxArea = 0;

        // Iterate to n (inclusive) to act as a pseudo-bar of height 0 at the end.
        // This ensures any remaining bars in the stack are processed.
        for (int i = 0; i <= n; i++) {
            int currentHeight = (i == n) ? 0 : heights[i];

            // If current bar is lower than the top of the stack, we must pop and calculate
            while (!st.empty() && currentHeight < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                
                // Width is bounded by the current index (right limit) and the new top of stack (left limit)
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * width);
            }
            
            st.push(i);
        }

        return maxArea;
    }
};

// ─── Driver ──────────────────────────────────────────────────────────────────
int main() {
    Solution sol;
    
    // Test Case: [2, 1, 5, 6, 2, 3]
    vector<int> heights1 = {2, 1, 5, 6, 2, 3};
    cout << "Test 1 result: " << sol.largestRectangleArea(heights1) << " (Expected: 10)" << endl;

    // Test Case: [2, 4]
    vector<int> heights2 = {2, 4};
    cout << "Test 2 result: " << sol.largestRectangleArea(heights2) << " (Expected: 4)" << endl;

    return 0;
}
