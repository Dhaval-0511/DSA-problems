class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        // Move all non-zero elements to the front
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] != 0) {
                nums[i] = nums[j];
                i++;
            }
        }
        // Fill the remaining positions with zeroes
        for (int k = i; k < nums.size(); ++k) {
            nums[k] = 0;
        }
    }
};

//prblm : https://leetcode.com/problems/move-zeroes