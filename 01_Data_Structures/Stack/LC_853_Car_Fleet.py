"""
Problem:  Car Fleet
Platform: LeetCode #853
Approach: Array Sorting + Monotonic Stack
Efficiency: Time O(N log N), Space O(N)
"""

from typing import List

class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        """
        Calculates the number of car fleets that will arrive at the destination.
        """
        if not position:
            return 0
            
        # Pair positions and speeds, then sort in descending order of position
        cars = sorted(zip(position, speed), reverse=True)
        
        stack = []
        
        for p, s in cars:
            time = (target - p) / s
            
            # If stack is empty or this car takes longer than the fleet ahead,
            # it forms a new fleet
            if not stack or time > stack[-1]:
                stack.append(time)
                
        return len(stack)

# ─── Driver & Testing Utilities ──────────────────────────────────────────────
def test_car_fleet():
    sol = Solution()
    
    # Case 1: Multiple fleets
    assert sol.carFleet(12, [10,8,0,5,3], [2,4,1,1,3]) == 3
    
    # Case 2: Single car
    assert sol.carFleet(10, [3], [3]) == 1
    
    # Case 3: Exact same time, merge into one fleet
    assert sol.carFleet(100, [0, 2, 4], [4, 2, 1]) == 1
    
    print("All Python Car Fleet test cases passed!")

if __name__ == "__main__":
    test_car_fleet()
