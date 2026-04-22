"""
Problem:  Valid Parentheses
Platform: LeetCode #020
Approach: Stack-based (LIFO)
Efficiency: Time O(N), Space O(N)
"""

class Solution:
    def isValid(self, s: str) -> bool:
        """
        Determines if the input string has validly nested and ordered parentheses.
        """
        # Map of closing -> opening brackets
        mapping = {")": "(", "}": "{", "]": "["}
        stack = []

        for char in s:
            if char in mapping:
                # Pop the top element if stack is not empty, else use dummy
                top_element = stack.pop() if stack else '#'
                
                # Check mapping
                if mapping[char] != top_element:
                    return False
            else:
                # Opening bracket, push to stack
                stack.append(char)

        # If stack is empty, it's valid
        return not stack

# ─── Driver & Testing Utilities ──────────────────────────────────────────────
def test_solution():
    sol = Solution()
    
    # Test cases: (Input, Expected)
    test_cases = [
        ("()", True),
        ("()[]{}", True),
        ("(]", False),
        ("([)]", False),
        ("{[]}", True),
        ("", True),
        ("[", False)
    ]
    
    for i, (s, expected) in enumerate(test_cases):
        result = sol.isValid(s)
        assert result == expected, f"Test Case {i} Failed: Input='{s}', Expected={expected}, Got={result}"
        print(f"Test Case {i} Passed: '{s}' -> {result}")

if __name__ == "__main__":
    test_solution()
