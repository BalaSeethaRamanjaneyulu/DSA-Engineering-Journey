/**
 * @file LC_150_Evaluate_Reverse_Polish_Notation.java
 * @author BalaSeethaRamanjaneyulu
 * @brief Java Solution for LeetCode 150: Evaluate Reverse Polish Notation
 */

import java.util.Stack;

public class LC_150_Evaluate_Reverse_Polish_Notation {
    /**
     * Evaluates an arithmetic expression in Reverse Polish Notation.
     * 
     * @param tokens Array of strings representing the expression.
     * @return int The evaluation result.
     */
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();

        for (String token : tokens) {
            if (token.equals("+") || token.equals("-") || token.equals("*") || token.equals("/")) {
                // Pop operands in correct order
                int b = stack.pop();
                int a = stack.pop();

                switch (token) {
                    case "+": stack.push(a + b); break;
                    case "-": stack.push(a - b); break;
                    case "*": stack.push(a * b); break;
                    case "/": stack.push(a / b); break; // Java division truncates toward zero
                }
            } else {
                // Parse integer and push to stack
                stack.push(Integer.parseInt(token));
            }
        }

        return stack.pop();
    }

    // ─── Driver ──────────────────────────────────────────────────────────────
    public static void main(String[] args) {
        LC_150_Evaluate_Reverse_Polish_Notation sol = new LC_150_Evaluate_Reverse_Polish_Notation();
        
        String[] tokens1 = {"2", "1", "+", "3", "*"};
        System.out.println("Test 1: " + sol.evalRPN(tokens1) + " (Expected: 9)");

        String[] tokens2 = {"4", "13", "5", "/", "+"};
        System.out.println("Test 2: " + sol.evalRPN(tokens2) + " (Expected: 6)");
    }
}
