class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        // If all digits were 9, we need to add one extra digit at the front
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

// prblm:https://leetcode.com/problems/plus-one