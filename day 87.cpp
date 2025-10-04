class Solution {
public:
    string removeKdigits(string num, int k) {
        string stk = ""; // acts as a stack to store answer digits

        for (char digit : num) {
            // While k > 0, and last stack digit is larger than current, pop it for a smaller result
            while (k > 0 && !stk.empty() && stk.back() > digit) {
                stk.pop_back();
                k--;
            }
            stk.push_back(digit);
        }
        
        // If still digits to remove (all were in decreasing order), remove from the end
        while (k > 0 && !stk.empty()) {
            stk.pop_back();
            k--;
        }
        
        // Remove leading zeros
        int start = 0;
        while (start < stk.size() && stk[start] == '0') {
            start++;
        }
        
        string result = stk.substr(start);
        // If result is empty, return "0"
        return result.empty() ? "0" : result;
    }
};

// prblm:https://leetcode.com/problems/remove-k-digits