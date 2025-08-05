class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findBoundary(nums, target, true);
        int last = findBoundary(nums, target, false);
        return {first, last};
    }
    
    int findBoundary(const vector<int>& nums, int target, bool findFirst) {
        int left = 0, right = nums.size() - 1;
        int boundary = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                boundary = mid;
                if (findFirst) {
                    right = mid - 1; // search left half
                } else {
                    left = mid + 1; // search right half
                }
            }
        }
        return boundary;
    }
};

// prblm:https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array