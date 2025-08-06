class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            
            // Determine which part is sorted
            if (nums[left] <= nums[mid]) { // Left part is sorted
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1; // Target in left part
                } else {
                    left = mid + 1; // Target in right part
                }
            } else { // Right part is sorted
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1; // Target in right part
                } else {
                    right = mid - 1; // Target in left part
                }
            }
        }
        return -1; // Not found
    }
};

// prblm:https://leetcode.com/problems/search-in-rotated-sorted-array