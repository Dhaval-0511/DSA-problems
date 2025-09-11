class Solution {
  public:
    void helper(string &s, int i, string &curr, vector<string> &ans) {
        if (i == s.size()) {
            if (!curr.empty()) ans.push_back(curr);
            return;
        }
        // Include s[i]
        curr.push_back(s[i]);
        helper(s, i + 1, curr, ans);
        curr.pop_back();
        // Exclude s[i]
        helper(s, i + 1, curr, ans);
    }

    vector<string> AllPossibleStrings(string s) {
        vector<string> ans;
        string curr;
        helper(s, 0, curr, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// prblm:https://www.geeksforgeeks.org/problems/power-set4302/1