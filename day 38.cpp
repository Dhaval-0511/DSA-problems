class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        string prefix = strs[0]; // Start with the first string as prefix
        for (int i = 1; i < strs.size(); i++) {
            // While current string does not start with prefix, shorten it
            while (strs[i].find(prefix) != 0) {
                prefix.pop_back(); // Remove last character
                if (prefix.empty()) return ""; // No common prefix
            }
        }
        return prefix;
    }
};

// prblm:https://leetcode.com/problems/longest-common-prefix