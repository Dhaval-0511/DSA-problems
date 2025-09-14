class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        sort(nums.begin(), nums.end()); // Sort to group duplicates
        backtrack(nums, 0, current, ans);
        return ans;
    }
    
    void backtrack(const vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& ans) {
        ans.push_back(current);
        for (int i = index; i < nums.size(); ++i) {
            // Skip duplicates at the same recursion level
            if (i > index && nums[i] == nums[i - 1]) continue;
            current.push_back(nums[i]);
            backtrack(nums, i + 1, current, ans);
            current.pop_back(); // Undo choice (backtrack)
        }
    }
};


// prblm:https://leetcode.com/problems/subsets-ii