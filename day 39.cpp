class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;

        // Hashmaps for mapping s->t and t->s
        unordered_map<char, char> mapST, mapTS;

        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            // If mapping exists, check consistency
            if (mapST.count(c1) && mapST[c1] != c2) return false;
            if (mapTS.count(c2) && mapTS[c2] != c1) return false;

            // Otherwise, establish mapping
            mapST[c1] = c2;
            mapTS[c2] = c1;
        }

        return true;
    }
};


// prblm:https://leetcode.com/problems/isomorphic-strings
