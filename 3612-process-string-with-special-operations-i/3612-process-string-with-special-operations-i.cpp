class Solution {
public:
    string processStr(string s) {
        string ans;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                ans += s[i];
            } 

            if (!ans.empty()) {
                string temp = ans;
                if (s[i] == '#') {
                    for (int i = 0; i < temp.size(); i++) {
                        ans += temp[i];
                    }
                }
        
                if (s[i] == '%') {
                    // for (int i = temp.size() - 1, j = 0; i >= 0; i--, j++) {
                    //     ans[j] = temp[i];
                    // }
                    ans = string(ans.rbegin(), ans.rend());
                }
        
                if (s[i] == '*') {
                    ans.erase(ans.size() - 1, 1);
                }
            }
        }

        return ans;
    }
};