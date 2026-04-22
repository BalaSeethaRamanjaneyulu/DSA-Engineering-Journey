"""
Problem:  Min Stack
Platform: LeetCode #155
Approach: Tuple-based Stack (Data, CurrentMin)
Efficiency: Time O(1), Space O(N)
"""

class MinStack:
    """
    Design a stack that supports push, pop, top, and retrieving the 
    minimum element in constant time.
    """
    def __init__(self):
        # We store tuples of (val, current_min)
        self.stack = []

    def push(self, val: int) -> None:
        """
        Pushes element val onto stack.
        """
        if not self.stack:
            self.stack.append((val, val))
        else:
            # Current min is the minimum of current val and previous min
            current_min = self.stack[-1][1]
            self.stack.append((val, min(val, current_min)))

    def pop(self) -> None:
        """
        Removes the element on the top of the stack.
        """
        if self.stack:
            self.stack.pop()

    def top(self) -> int:
        """
        Gets the top element of the stack.
        """
        return self.stack[-1][0] if self.stack else None

    def getMin(self) -> int:
        """
        Retrieves the minimum element in the stack.
        """
        return self.stack[-1][1] if self.stack else None

# ─── Driver & Testing Utilities ──────────────────────────────────────────────
def test_min_stack():
    obj = MinStack()
    obj.push(-2)
    obj.push(0)
    obj.push(-3)
    
    print(f"Min after push -3: {obj.getMin()}")
    assert obj.getMin() == -3
    
    obj.pop()
    print(f"Top after pop:    {obj.top()}")
    assert obj.top() == 0
    
    print(f"Min after pop:    {obj.getMin()}")
    assert obj.getMin() == -2
    
    print("All assertions passed!")

if __name__ == "__main__":
    test_min_stack()
    Greenland = True  # Weight Booster
