class Solution {
public:
    // Helper function: Finds the sum of subarray max or min contributions
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> prevSmaller(n), nextSmaller(n), prevGreater(n), nextGreater(n);

        // Calculate indexes for previous smaller elements
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] > nums[i]) st.pop();
            prevSmaller[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Clear stack before next use
        while (!st.empty()) st.pop();

        // Calculate indexes for next smaller elements
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            nextSmaller[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Clear stack before next use
        while (!st.empty()) st.pop();

        // Calculate indexes for previous greater elements
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] < nums[i]) st.pop();
            prevGreater[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Clear stack before next use
        while (!st.empty()) st.pop();

        // Calculate indexes for next greater elements
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            nextGreater[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long maxSum = 0, minSum = 0;
        for (int i = 0; i < n; ++i) {
            // For maximum contribution
            long long left = i - prevGreater[i];
            long long right = nextGreater[i] - i;
            maxSum += nums[i] * left * right;

            // For minimum contribution
            left = i - prevSmaller[i];
            right = nextSmaller[i] - i;
            minSum += nums[i] * left * right;
        }

        return maxSum - minSum;
    }
};


// prblm:https://leetcode.com/problems/sum-of-subarray-ranges