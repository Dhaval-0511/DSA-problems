// prblm: Print subarray with maximum subarray sum (extended version of above problem)

class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
        long long maxSum = -1, currSum = 0; // use long long in case of big sums
        int maxStart = -1, maxEnd = -1, currStart = 0;
        int n = arr.size();
        
        for (int i = 0; i < n; ++i) {
            if (arr[i] >= 0) {
                currSum += arr[i];
                // if not already started, note starting index
                if (currStart == -1)
                    currStart = i;
            } else {
                // compare and possibly update max subarray
                if (currSum > maxSum || (currSum == maxSum && currStart < maxStart)) {
                    maxSum = currSum;
                    maxStart = currStart;
                    maxEnd = i - 1;
                }
                currSum = 0;
                currStart = -1;
            }
        }
        // Check after the loop (in case best subarray ends at array end)
        if (currSum > maxSum || (currSum == maxSum && currStart < maxStart)) {
            maxSum = currSum;
            maxStart = currStart;
            maxEnd = n - 1;
        }
        
        if (maxSum == -1) return {-1};
        
        vector<int> ans;
        for (int i = maxStart; i <= maxEnd; ++i)
            ans.push_back(arr[i]);
        return ans;
    }
};