class Solution {
public:
    bool rotateString(string s, string goal) {
        // If lengths differ, impossible
        if (s.size() != goal.size()) return false;
        
        // Concatenate s with itself
        string doubled = s + s;
        
        // If goal exists as a substring
        return doubled.find(goal) != string::npos;
    }
};

// prblm:https://leetcode.com/problems/rotate-string
