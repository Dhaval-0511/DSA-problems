#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int longest = 0;
        
        for (int num : num_set) {
            // Only check for the start of a sequence
            if (!num_set.count(num - 1)) {
                int current_num = num;
                int count = 1;
                
                while (num_set.count(current_num + 1)) {
                    current_num++;
                    count++;
                }
                
                longest = max(longest, count);
            }
        }
        return longest;
    }
};

// prblm:https://leetcode.com/problems/longest-consecutive-sequence