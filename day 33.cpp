class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            // Ensure mid is even
            if (mid % 2 == 1) mid--;
            
            if (nums[mid] == nums[mid + 1]) {
                // Single element is in the right half
                low = mid + 2;
            } else {
                // Single element is in the left half including mid
                high = mid;
            }
        }
        
        // low will be at the single element
        return nums[low];
    }
};

// prblm:https://leetcode.com/problems/single-element-in-a-sorted-array