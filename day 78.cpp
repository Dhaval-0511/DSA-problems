class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num; // Each duplicate cancels itself, leaving the unique number at last
        }
        return result;
    }
};


// prblm:https://leetcode.com/problems/single-number