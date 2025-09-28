class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Hash map to store the next greater element for each number in nums2
        unordered_map<int, int> nge;
        // Stack to keep numbers for which we are yet to find the next greater element
        stack<int> st;

        // Iterate through nums2 to fill nge (next greater element mapping)
        for (int num : nums2) {
            // While there is a number on stack and current num is greater,
            // current num is the next greater for stack top
            while (!st.empty() && num > st.top()) {
                nge[st.top()] = num;
                st.pop();
            }
            // Push the current num on stack to find its next greater element in future
            st.push(num);
        }

        // For those remaining in stack, there is no next greater element
        while (!st.empty()) {
            nge[st.top()] = -1;
            st.pop();
        }

        // Prepare answer for nums1 by looking up precomputed values
        vector<int> res;
        for (int num : nums1) {
            res.push_back(nge[num]);
        }
        return res;
    }
};


// prblm:https://leetcode.com/problems/next-greater-element-i