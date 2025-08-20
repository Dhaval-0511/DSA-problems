class Solution {
public:
    int maxDepth(string s) {
        int currentDepth = 0;
        int maxDepth = 0;
        for (char c : s) {
            if (c == '(') {
                currentDepth++;
                if (currentDepth > maxDepth) {
                    maxDepth = currentDepth;
                }
            } else if (c == ')') {
                currentDepth--;
            }
        }
        return maxDepth;
    }
};

// prblm: : https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses