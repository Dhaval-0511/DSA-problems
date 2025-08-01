class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool firstRowZero = false, firstColZero = false;
        
        // Check if first row needs to be zeroed
        for (int j = 0; j < n; ++j)
            if (matrix[0][j] == 0)
                firstRowZero = true;
        
        // Check if first column needs to be zeroed
        for (int i = 0; i < m; ++i)
            if (matrix[i][0] == 0)
                firstColZero = true;
        
        // Use first row and column to record zero!
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // Zero cells based on marks in row/col
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Zero the first row if needed
        if (firstRowZero)
            for (int j = 0; j < n; ++j)
                matrix[0][j] = 0;
        
        // Zero the first column if needed
        if (firstColZero)
            for (int i = 0; i < m; ++i)
                matrix[i][0] = 0;
    }
};

// prblm:https://leetcode.com/problems/set-matrix-zeroes