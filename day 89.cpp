class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0; // Edge case: empty matrix

        int maxArea = 0;
        int m = matrix.size();
        int n = matrix[0].size();

        // heights array used to build the histogram for each row
        vector<int> heights(n, 0);

        for (int i = 0; i < m; ++i) {
            // Update the histogram heights for current row
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0; // Reset height if '0'
                }
            }
            // After updating heights, calculate max area for this histogram
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }

private:
    // Helper function: Largest Rectangle in Histogram (Leetcode #84)
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        heights.push_back(0); // Sentinel to ensure final flush

        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int h = heights[st.top()]; st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        heights.pop_back(); // Remove sentinel
        return maxArea;
    }
};


// prblm:https://leetcode.com/problems/maximal-rectangle