class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charCount;
        int l = 0, maxLen = 0;
        for (int r = 0; r < s.size(); r++) {
            charCount[s[r]]++;
            while (charCount[s[r]] > 1) {
                charCount[s[l]]--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};


// prblm:https://leetcode.com/problems/longest-substring-without-repeating-characters