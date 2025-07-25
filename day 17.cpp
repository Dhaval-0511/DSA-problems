class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i = n - 2;

        // Step 1: find first decreasing element from the back
        while (i >= 0 && nums[i] >= nums[i + 1]) i--;
        
        if (i >= 0) {
            // Step 2: find element just larger than nums[i] from the right
            int j = n - 1;
            while (nums[j] <= nums[i]) j--;
            swap(nums[i], nums[j]);
        }
        // Step 3: reverse the suffix
        reverse(nums.begin() + i + 1, nums.end());
    }
};

// prblm:https://leetcode.com/problems/next-permutation