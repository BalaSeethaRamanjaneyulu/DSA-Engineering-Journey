/**
 * @file LC_739_Daily_Temperatures.cpp
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 739: Daily Temperatures
 *
 * Problem: Given an array of integers temperatures, return an array answer 
 * such that answer[i] is the number of days you have to wait after the i-th day 
 * to get a warmer temperature.
 *
 * Platform: LeetCode #739
 * Approach: Monotonic Stack (Decreasing)
 * Time:     O(N)
 * Space:    O(N)
 * Link:     https://leetcode.com/problems/daily-temperatures/
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    /**
     * @brief Finds the number of days until a warmer temperature for each day.
     * 
     * @param temperatures Vector of daily temperatures.
     * @return vector<int> Vector of wait times.
     */
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> st; // Stores indices of temperatures

        for (int i = 0; i < n; i++) {
            // While current temperature is warmer than the temperature at the stack's top index
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevIndex = st.top();
                st.pop();
                result[prevIndex] = i - prevIndex;
            }
            // Push current index to stack
            st.push(i);
        }

        return result;
    }
};

// ─── Driver ──────────────────────────────────────────────────────────────────
void printVector(const vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << endl;
}

int main() {
    Solution sol;
    
    // Test Case: [73, 74, 75, 71, 69, 72, 76, 73]
    vector<int> temp1 = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res1 = sol.dailyTemperatures(temp1);
    cout << "Test 1: "; printVector(res1); 
    // Expected: [1, 1, 4, 2, 1, 1, 0, 0]

    // Test Case: [30, 40, 50, 60]
    vector<int> temp2 = {30, 40, 50, 60};
    vector<int> res2 = sol.dailyTemperatures(temp2);
    cout << "Test 2: "; printVector(res2);
    // Expected: [1, 1, 1, 0]

    return 0;
}
