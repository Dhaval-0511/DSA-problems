#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numToIndex;   // Maps number to its index

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];

            // Check if the complement exists in the hash map
            if (numToIndex.find(complement) != numToIndex.end()) {
                return {numToIndex[complement], i};
            }

            // If not found, store the number with its index
            numToIndex[nums[i]] = i;
        }

        // According to the problem statement, there is always exactly one solution
        return {};
    }
};

//problem: https://leetcode.com/problems/two-sum