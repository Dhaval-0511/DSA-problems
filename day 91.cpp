#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;  // stores indices of elements
        
        for (int i = 0; i < nums.size(); ++i) {
            // Remove indices that are out of this window's range
            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();
            
            // Remove elements smaller than the current element nums[i]
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            
            // Add current element index at the back
            dq.push_back(i);
            
            // Starting from i == k-1, add max for each window
            if (i >= k - 1)
                result.push_back(nums[dq.front()]);
        }
        return result;
    }
};


// prblm:https://leetcode.com/problems/sliding-window-maximum