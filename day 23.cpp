#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSums;
        prefixSums[0] = 1;  // Base case: one prefix sum of 0 (empty subarray)

        int sum = 0;
        int count = 0;
        for (int num : nums) {
            sum += num;
            if (prefixSums.find(sum - k) != prefixSums.end()) {
                count += prefixSums[sum - k];
            }
            prefixSums[sum]++;
        }
        return count;
    }
};

// prblm:https://leetcode.com/problems/subarray-sum-equals-k