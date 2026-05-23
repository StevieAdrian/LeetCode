class Solution {
public:
    string longestPalindrome(string s) {
        int len = 0;
        int maxx = 0;
        int start = 0;

        for (int i = 0; i < s.size(); i++) {
            int left = i;
            int right = i;

            while (left >= 0 && right < s.size()) {
                if (s[left] == s[right]) {
                    len = max(len, right - left + 1);
                    if (len > maxx) {
                        maxx = len;
                        start = left;
                    }
                    left--; 
                    right++;
                } else {
                    break;
                }

            }

            left = i;
            right = i+1;
            while (left >= 0 && right < s.size()) {
                if (s[left] == s[right]) {
                    len = max(len, right - left + 1);
                    if (len > maxx) {
                        maxx = len;
                        start = left;
                    }
                    left--; 
                    right++;
                } else {
                    break;
                }

            }
        }

        return s.substr(start, maxx);
    }
};