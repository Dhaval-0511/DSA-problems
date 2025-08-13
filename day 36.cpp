#include <sstream>
#include <vector>
#include <algorithm>

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word;
        stringstream ss(s);

        // Extract words (stringstream automatically skips extra spaces)
        while (ss >> word) {
            words.push_back(word);
        }

        // Reverse the list of words
        reverse(words.begin(), words.end());

        // Join with a single space
        string result;
        for (int i = 0; i < words.size(); i++) {
            if (i > 0) result += " ";
            result += words[i];
        }
        return result;
    }
};

// prblm:https://leetcode.com/problems/reverse-words-in-a-string