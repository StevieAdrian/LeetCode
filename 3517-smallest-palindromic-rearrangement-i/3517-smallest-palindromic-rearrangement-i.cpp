class Solution {
public:
    string smallestPalindrome(string s) {
        // int len = s.length();
        // int partition = len / 2;

        // sort(s.begin(), s.begin() + partition);
        // cout << s << endl;

        // for (int i = 0; i < partition; ++i) {
        //     s[len - 1 - i] = s[i];
        // }

        // return s;
        string ans;
        unordered_map<char, int> ctr;

        for (int i = 0; i < s.size(); i++) {
            ctr[s[i]]++;
        }
        
        string temp;
        char temp2 = '\0';

        for (auto p: ctr) {
            for (int i = 0; i < p.second / 2; i++) {
                temp += p.first;
            }
            if (p.second % 2 == 1){
                temp2 = p.first;
            }
        }

        ans = temp;
        string temp3 = temp;

        sort(ans.begin(), ans.end());
        if (temp2 != '\0') {
            ans += temp2;
        }
        sort(temp3.begin(), temp3.end(), greater<int>());

        return ans + temp3;
    }
};