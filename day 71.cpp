class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        backtrack(0, s, path, ans);
        return ans;
    }
    
private:
    void backtrack(int start, const string& s, vector<string>& path, vector<vector<string>>& ans) {
        if (start == s.size()) {
            ans.push_back(path);
            return;
        }
        for (int end = start; end < s.size(); ++end) {
            if (isPalindrome(s, start, end)) {
                path.push_back(s.substr(start, end - start + 1));
                backtrack(end + 1, s, path, ans);
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            ++left;
            --right;
        }
        return true;
    }
};


// prblm:https://leetcode.com/problems/palindrome-partitioning