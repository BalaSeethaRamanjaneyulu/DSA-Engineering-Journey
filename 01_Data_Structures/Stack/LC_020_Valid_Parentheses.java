/**
 * @file LC_020_Valid_Parentheses.java
 * @author BalaSeethaRamanjaneyulu
 * @brief Java Solution for LeetCode 020: Valid Parentheses
 */

import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

public class LC_020_Valid_Parentheses {
    /**
     * Checks if the input string of parentheses is balanced using a Stack.
     * 
     * @param s The input string.
     * @return boolean true if balanced, false otherwise.
     */
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        Map<Character, Character> mapping = new HashMap<>();
        mapping.put(')', '(');
        mapping.put('}', '{');
        mapping.put(']', '[');

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            // If it's a closing bracket
            if (mapping.containsKey(c)) {
                // Pop the top element if stack is not empty, else use a dummy
                char topElement = stack.isEmpty() ? '#' : stack.pop();

                // If the popped element doesn't match the mapping, it's invalid
                if (topElement != mapping.get(c)) {
                    return false;
                }
            } else {
                // It's an opening bracket
                stack.push(c);
            }
        }

        return stack.isEmpty();
    }

    // ─── Driver ──────────────────────────────────────────────────────────────
    public static void main(String[] args) {
        LC_020_Valid_Parentheses sol = new LC_020_Valid_Parentheses();
        System.out.println("Test 1: " + (sol.isValid("()[]{}") ? "Valid" : "Invalid"));
        System.out.println("Test 2: " + (sol.isValid("([)]") ? "Valid" : "Invalid"));
        System.out.println("Test 3: " + (sol.isValid("{[]}") ? "Valid" : "Invalid"));
    }
}
