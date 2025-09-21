class Solution {
public:
    int beautySum(string s) {
        int ans = 0; // This will store the final sum of beauties
        int n = s.size();

        // Outer loop: starting index of substring
        for (int i = 0; i < n; ++i) {
            vector<int> freq(26, 0); // Frequency array for each lowercase char

            // Inner loop: ending index of substring
            for (int j = i; j < n; ++j) {
                freq[s[j] - 'a']++; // Update frequency for the current char

                // Find min and max frequency among present characters
                int maxFreq = 0, minFreq = INT_MAX;
                for (int k = 0; k < 26; ++k) {
                    if (freq[k] > 0) {
                        maxFreq = max(maxFreq, freq[k]);
                        minFreq = min(minFreq, freq[k]);
                    }
                }
                // Add the beauty (maxFreq - minFreq) to answer
                ans += (maxFreq - minFreq);
            }
        }
        return ans;
    }
};

// prblm:https://leetcode.com/problems/sum-of-beauty-of-all-substrings