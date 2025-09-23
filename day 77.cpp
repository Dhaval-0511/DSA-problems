class Solution {
public:
    int minBitFlips(int start, int goal) {
        // XOR gives bits that are different in start and goal
        int diff = start ^ goal;

        // Count the number of set bits (1s) in diff
        int count = 0;
        while (diff) {
            // Increment count if the least significant bit is 1
            count += (diff & 1);
            // Right-shift diff to check the next bit
            diff >>= 1;
        }
        return count;
    }
};


// prblm:https://leetcode.com/problems/minimum-bit-flips-to-convert-number