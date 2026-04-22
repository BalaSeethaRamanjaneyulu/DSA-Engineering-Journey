/**
 * @file LC_155_Min_Stack.java
 * @author BalaSeethaRamanjaneyulu
 * @brief Java Solution for LeetCode 155: Min Stack
 */

import java.util.Stack;

public class LC_155_Min_Stack {
    private Stack<Integer> stack;
    private Stack<Integer> minStack;

    public LC_155_Min_Stack() {
        stack = new Stack<>();
        minStack = new Stack<>();
    }

    /**
     * Pushes val onto the stack.
     * 
     * @param val The value to push.
     */
    public void push(int val) {
        stack.push(val);
        // If minStack is empty or val <= current minimum, push to minStack
        if (minStack.isEmpty() || val <= minStack.peek()) {
            minStack.push(val);
        }
    }

    /**
     * Removes the top element.
     */
    public void pop() {
        // Use .equals() for object comparison
        if (stack.peek().equals(minStack.peek())) {
            minStack.pop();
        }
        stack.pop();
    }

    /**
     * Gets the top element.
     * 
     * @return int The top element.
     */
    public int top() {
        return stack.peek();
    }

    /**
     * Gets the minimum element.
     * 
     * @return int The current minimum.
     */
    public int getMin() {
        return minStack.peek();
    }

    // ─── Driver ──────────────────────────────────────────────────────────────
    public static void main(String[] args) {
        LC_155_Min_Stack obj = new LC_155_Min_Stack();
        obj.push(-2);
        obj.push(0);
        obj.push(-3);
        System.out.println("Min: " + obj.getMin()); // -3
        obj.pop();
        System.out.println("Top: " + obj.top());    // 0
        System.out.println("Min: " + obj.getMin()); // -2
    }
}
