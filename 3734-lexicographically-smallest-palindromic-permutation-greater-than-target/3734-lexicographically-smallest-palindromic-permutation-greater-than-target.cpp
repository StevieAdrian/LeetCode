class Solution {
public:
    bool permutate(string& half, string& curr, vector<bool>& used, string& target, string& ans, int cmp, char middle, int n) {
        if (curr.length() == half.length()) {
            string palindrome = curr;

            if (n % 2 == 1) {
                palindrome += middle;
            }

            for (int i = curr.length() - 1; i >= 0; i--) {
                palindrome += curr[i];
            }

            if (palindrome > target) {
                ans = palindrome;
                return true;
            }

            return false;
        }

        int pos = curr.length();

        for (int i = 0; i < half.length(); i++) {
            if (used[i]) continue;
            if (i > 0 && half[i] == half[i - 1] && !used[i - 1]) continue;

            char c = half[i];

            int newCmp = cmp;

            if (cmp == 0) {
                if (c < target[pos]) {
                    newCmp = -1;
                }
                else if (c > target[pos]) {
                    newCmp = 1;
                }
            }

            if (newCmp < 0) continue;

            used[i] = true;
            curr += c;

            if (permutate(half, curr, used, target, ans, newCmp, middle, n)) {
                return true;
            }

            curr.pop_back();
            used[i] = false;
        }

        return false;
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();

        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        int odd = 0;
        char middle = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                odd++;
                middle = 'a' + i;
            }
        }

        if (odd > 1) return "";

        string half = "";

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < freq[i] / 2; j++) {
                half += char('a' + i);
            }
        }

        vector<bool> used(half.length(), false);

        string curr = "";
        string ans = "";

        permutate(half, curr, used, target, ans, 0, middle, n);

        return ans;
    }
};