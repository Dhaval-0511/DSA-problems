class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1); // Initialize result with -1
        stack<int> st;          // Stack to store indices

        // Traverse the array twice for circular effect
        for (int i = 0; i < 2 * n; ++i) {
            int num = nums[i % n];
            // Pop smaller elements and assign result
            while (!st.empty() && nums[st.top()] < num) {
                res[st.top()] = num;
                st.pop();
            }
            // For the first pass, push indices onto stack
            if (i < n) {
                st.push(i);
            }
        }
        return res;
    }
};

// prblm:https://leetcode.com/problems/next-greater-element-ii