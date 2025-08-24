class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> n;
        int l = 0;
        int len = 0;

        for (int r = 0; r < s.size(); r++) {
            char c = s[r];

            if (n.count(c) && n[c] >= l) {
                l = n[c] + 1;
            }

            n[c] = r; 
            len = max(len, r - l + 1); 
        }

        return len;
    }
};