class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int depth = 0;
        
        for (char c : s) {
            if (c == '(') {
                if (depth > 0) { // not outermost
                    result.push_back(c);
                }
                depth++;
            } else { // c == ')'
                depth--;
                if (depth > 0) { // not outermost
                    result.push_back(c);
                }
            }
        }
        
        return result;
    }
};

// problem:https://leetcode.com/problems/remove-outermost-parentheses