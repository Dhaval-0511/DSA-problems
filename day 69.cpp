class Solution {
public:
    void backtrack(int start, int k, int n, vector<int>& curr, vector<vector<int>>& res) {
        if (curr.size() == k && n == 0) {
            res.push_back(curr);
            return;
        }
        if (curr.size() >= k || n <= 0)
            return; // Prune paths that can't reach k or n

        for (int i = start; i <= 9; ++i) {
            curr.push_back(i);
            backtrack(i + 1, k, n - i, curr, res); // numbers used once; next number > i
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(1, k, n, curr, res);
        return res;
    }
};


// prblm:https://leetcode.com/problems/combination-sum-iii