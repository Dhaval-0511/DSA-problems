class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        // If the list has just one element or is not rotated
        if (nums[left] <= nums[right])
            return nums[left];
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // If mid element is greater than the rightmost, min must be right of mid
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                // min is at mid or in the left side
                right = mid;
            }
        }
        // when left == right, that's the smallest
        return nums[left];
    }
};

// prblm:https://leetcode.com/problems/find-minimum-in-rotated-sorted-array