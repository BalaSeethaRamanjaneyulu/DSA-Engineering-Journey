/**
 * @file LC_853_Car_Fleet.cpp
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 853: Car Fleet
 *
 * Problem: There are n cars going to the same destination along a one-lane road. 
 * Calculate how many car fleets will arrive at the destination.
 *
 * Platform: LeetCode #853
 * Approach: Array Sorting + Stack
 * Time:     O(N log N) due to sorting
 * Space:    O(N) for storing car pairs
 * Link:     https://leetcode.com/problems/car-fleet/
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @brief Calculates the number of car fleets.
     * 
     * @param target The destination distance.
     * @param position Vector of car starting positions.
     * @param speed Vector of car speeds.
     * @return int Number of fleets.
     */
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;

        // Pair up position and speed: {position, speed}
        vector<pair<int, int>> cars;
        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }

        // Sort cars by position descending (closest to target first)
        sort(cars.rbegin(), cars.rend());

        stack<double> st; // Stores arrival times of fleets

        for (int i = 0; i < n; i++) {
            // Time = (Target - Position) / Speed
            double time = (double)(target - cars[i].first) / cars[i].second;

            // If the stack is empty, or the current car takes MORE time than the fleet 
            // in front of it (top of stack), it forms a new fleet.
            // If it takes LESS or EQUAL time, it catches up and joins the fleet in front,
            // so we do NOT push it (it gets absorbed).
            if (st.empty() || time > st.top()) {
                st.push(time);
            }
        }

        // The number of distinct fleets is the size of the stack
        return st.size();
    }
};

// ─── Driver ──────────────────────────────────────────────────────────────────
int main() {
    Solution sol;
    
    // Test Case: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
    int target1 = 12;
    vector<int> pos1 = {10, 8, 0, 5, 3};
    vector<int> speed1 = {2, 4, 1, 1, 3};
    cout << "Test 1 result: " << sol.carFleet(target1, pos1, speed1) << " (Expected: 3)" << endl;

    // Test Case: target = 10, position = [3], speed = [3]
    int target2 = 10;
    vector<int> pos2 = {3};
    vector<int> speed2 = {3};
    cout << "Test 2 result: " << sol.carFleet(target2, pos2, speed2) << " (Expected: 1)" << endl;

    return 0;
}
