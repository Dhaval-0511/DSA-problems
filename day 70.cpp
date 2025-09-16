class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        // Mapping from digit to corresponding letters
        vector<string> mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        vector<string> result;
        string current;
        backtrack(0, digits, mapping, current, result);
        return result;
    }

private:
    void backtrack(int i, const string &digits, const vector<string> &mapping,
                   string &current, vector<string> &result) {
        if (i == digits.size()) {
            result.push_back(current);
            return;
        }
        int num = digits[i] - '0';
        for (char ch : mapping[num]) {
            current.push_back(ch);
            backtrack(i + 1, digits, mapping, current, result);
            current.pop_back();
        }
    }
};

// prblm:https://leetcode.com/problems/letter-combinations-of-a-phone-number