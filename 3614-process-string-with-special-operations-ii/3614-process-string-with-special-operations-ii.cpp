class Solution {
public:
    char processStr(string s, long long k) {
        vector<long long> len(s.size());

        long long curr = 0;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (islower(c)) {
                curr++;
            } else if (c == '*') {
                curr = max(0LL, curr - 1);
            } else if (c == '#') {
                curr *= 2;
            }

            len[i] = curr;
        }

        if (k >= curr) {
            return '.';
        }

        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];
            long long bbb = (i == 0 ? 0 : len[i - 1]);

            if (islower(c)) {
                if (k == bbb) {
                    return c;
                }
            } else if (c == '#') {
                if (bbb > 0) {
                    k %= bbb;
                }
            } else if (c == '%') {
                if (bbb > 0) {
                    k = bbb - 1 - k;
                }
            }
        }

        return '.';
    }
};