class Solution {
public:
    bool permutate(string& s, string& curr, vector<bool>& used, string& target, string& ans, int cmp) {
        if (curr.length() == s.length()) {
            if (cmp > 0) {
                ans = curr;
                return true;
            }
            return false;
        }

        int pos = curr.length();

        for (int i = 0; i < s.length(); i++) {
            if (used[i]) continue;

            if (i > 0 && s[i] == s[i - 1] && !used[i - 1]) continue;

            int newCmp = cmp;
            if (cmp == 0) {
                if (s[i] < target[pos]) {
                    newCmp = -1;
                } else if (s[i] > target[pos]) {
                    newCmp = 1;
                }
            }

            if (newCmp < 0) {
                continue;
            }

            used[i] = true;
            curr += s[i];

            if (permutate(s, curr, used, target, ans, newCmp)) {
                return true;
            }

            curr.pop_back();
            used[i] = false;
        }

        return false;
    }

    string lexGreaterPermutation(string s, string target) {
        sort(s.begin(), s.end());

        vector<bool> used(s.length(), false);
        string curr = "";
        string ans = "";

        permutate(s, curr, used, target, ans, 0);

        return ans;
    }
};