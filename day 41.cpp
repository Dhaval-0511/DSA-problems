class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        vector<int> count(26, 0);  // for a-z

        // Count chars in s
        for (char c : s) {
            count[c - 'a']++;
        }

        // Subtract chars from t
        for (char c : t) {
            count[c - 'a']--;
        }

        // Check all frequencies
        for (int val : count) {
            if (val != 0)
                return false;
        }

        return true;
    }
};


// prblm:https://leetcode.com/problems/valid-anagram