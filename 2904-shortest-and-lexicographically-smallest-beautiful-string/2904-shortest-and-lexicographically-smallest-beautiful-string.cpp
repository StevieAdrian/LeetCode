class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int l = 0;
        int count = 0;
        for (int r = 0; r < s.size(); r++) {
            if (s[r] == '1') {
                count++;
            }

            while (count > k) {
                if (s[l] == '1') {
                    count--;
                }
                l++;
            }

            if (count == k) {
                while (l <= r && s[l] == '0') {
                    l++;
                }

                string temp = s.substr(l, r - l + 1);
                if (ans.empty() || temp.length() < ans.length() || (temp.length() == ans.length() && temp < ans)) {
                    ans = temp;
                }
            }
            // temp = "";
            // int count = 0;
            // bool flag = false;
            // for (int j = i; j < s.size(); j++) {
            //     temp += s[j];
            //     if (s[j] == '1') {
            //         count++;
            //     }

            //     if (count >= k) {
            //         flag = true;
            //         break;
            //     }
            // }
            // if (flag == true) {
            //     mpp[temp] = temp.length();
            // }
        }

        // for (auto p: mpp) {
        //     cout << p.first << " -> " << p.second << endl;
        // }

        // vector<pair<string, int>> temp2(mpp.begin(), mpp.end());
        // sort(temp2.begin(), temp2.end(), [](auto a, auto b) {
        //     if (a.second != b.second) {
        //         return a.second < b.second;
        //     }
            
        //     return a.first < b.first;
        // });

        // string ans = "";
        // if (!temp2.empty()) {
        //     ans = temp2[0].first;
        // }

        return ans;
    }
};