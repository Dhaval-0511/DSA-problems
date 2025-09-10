class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(n, n, "", ans);
        return ans;
    }
private:
    void dfs(int open, int close, string curr, vector<string>& ans) {
        if (open == 0 && close == 0) {
            ans.push_back(curr);
            return;
        }
        if (open > 0) {
            dfs(open - 1, close, curr + '(', ans);
        }
        if (close > open) {
            dfs(open, close - 1, curr + ')', ans);
        }
    }
};


// prblm:https://leetcode.com/problems/generate-parentheses