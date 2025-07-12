class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int i = 0; // Pointer to last unique element
        for (int j = 1; j < nums.size(); ++j) {
            if (nums[j] != nums[i]) {
                i++; // Move to next position
                nums[i] = nums[j]; // Copy unique element forward
            }
        }
        return i + 1; // Number of unique elements
    }
};

// problm : https://leetcode.com/problems/remove-duplicates-from-sorted-array