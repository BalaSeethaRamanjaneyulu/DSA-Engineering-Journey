"""
Problem:  Evaluate Reverse Polish Notation
Platform: LeetCode #150
Approach: Stack-based Evaluation (LIFO)
Efficiency: Time O(N), Space O(N)
"""

from typing import List

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        """
        Evaluates the value of an arithmetic expression in RPN.
        """
        stack = []
        
        for token in tokens:
            if token in {"+", "-", "*", "/"}:
                # Note the order: b is the top element, a is the one below it
                b = stack.pop()
                a = stack.pop()
                
                if token == "+":
                    stack.append(a + b)
                elif token == "-":
                    stack.append(a - b)
                elif token == "*":
                    stack.append(a * b)
                elif token == "/":
                    # Python's // is floor division. 
                    # For truncation toward zero (LC requirement), use int(a / b)
                    stack.append(int(a / b))
            else:
                stack.append(int(token))
                
        return stack[0]

# ─── Driver & Testing Utilities ──────────────────────────────────────────────
def test_rpn():
    sol = Solution()
    
    # Case 1: (2 + 1) * 3 = 9
    assert sol.evalRPN(["2", "1", "+", "3", "*"]) == 9
    
    # Case 2: 4 + (13 / 5) = 6 (truncation toward zero: 13/5 = 2.6 -> 2)
    assert sol.evalRPN(["4", "13", "5", "/", "+"]) == 6
    
    # Case 3: 10 * (6 / ((9 + 3) * -11)) + 17 + 5
    # Truncation check: 6 / -132 = -0.045 -> 0
    assert sol.evalRPN(["10","6","9","3","+","-11","*","/","*","17","+","5","+"]) == 22
    
    print("All Python RPN test cases passed!")

if __name__ == "__main__":
    test_rpn()
