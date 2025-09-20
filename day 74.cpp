class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        // Skip leading spaces
        while (i < n && s[i] == ' ') i++;

        // Handle sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // Read digits and ignore leading zeros
        long result = 0;
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Overflow check before appending digit
            if (result > (INT_MAX - digit) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return sign * result;
    }
};


// prblm:https://leetcode.com/problems/string-to-integer-atoi