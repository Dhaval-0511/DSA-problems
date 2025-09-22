#include <climits>  // for INT_MIN, INT_MAX
#include <cstdlib>  // for llabs

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Overflow case: INT_MIN / -1
        if (dividend == INT_MIN && divisor == -1) 
            return INT_MAX;
        
        // Determine the sign of the quotient
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Use long long for safe abs to avoid overflow
        long long a = llabs((long long)dividend);
        long long b = llabs((long long)divisor);

        long long result = 0;

        // Bitwise division
        for (int i = 31; i >= 0; i--) {
            if ((a >> i) >= b) {
                a -= (b << i);
                result += (1LL << i);
            }
        }

        if (negative) return -result;
        else return result;
    }
};


// prblm:https://leetcode.com/problems/divide-two-integers