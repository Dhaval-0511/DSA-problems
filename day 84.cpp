class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;

        // Arrays to store the distance to previous and next less element
        vector<int> ple(n), nle(n);

        // Monotonic stack for Previous Less Element (PLE)
        stack<int> s1;
        for (int i = 0; i < n; ++i) {
            while (!s1.empty() && arr[s1.top()] > arr[i])
                s1.pop();
            ple[i] = s1.empty() ? -1 : s1.top();
            s1.push(i);
        }

        // Monotonic stack for Next Less Element (NLE)
        stack<int> s2;
        for (int i = n-1; i >= 0; --i) {
            while (!s2.empty() && arr[s2.top()] >= arr[i])
                s2.pop();
            nle[i] = s2.empty() ? n : s2.top();
            s2.push(i);
        }

        // Calculate the result
        long long result = 0;
        for (int i = 0; i < n; ++i) {
            long long left = i - ple[i];
            long long right = nle[i] - i;
            result = (result + arr[i] * left * right) % MOD;
        }
        return (int)result;
    }
};


// prblm:https://leetcode.com/problems/sum-of-subarray-minimums