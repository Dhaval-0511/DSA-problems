class Solution {
public:
    string largestOddNumber(string num) {
        // Start from last char and move backwards
        for (int i = num.size() - 1; i >= 0; --i) {
            int digit = num[i] - '0';
            if (digit % 2 == 1) {
                // Found an odd digit, return substring up to it
                return num.substr(0, i + 1);
            }
        }
        // No odd digit found
        return "";
    }
};

// prblm:https://leetcode.com/problems/largest-odd-number-in-string