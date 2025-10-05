class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st; // Stack holds indices
        int maxArea = 0;
        
        for (int i = 0; i <= n; i++) {
            // Use height 0 as a sentinel at the end to flush stack
            int h = (i == n ? 0 : heights[i]);
            // Maintain stack of increasing heights
            while (!st.empty() && h < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                // Width calculation: if stack is empty, width = i, else width = i - st.top() - 1
                int width = st.empty() ? i : (i - st.top() - 1);
                maxArea = max(maxArea, height * width);
            }
            st.push(i); // Push current index to stack
        }
        return maxArea;
    }
};

// prblm:https://leetcode.com/problems/largest-rectangle-in-histogram