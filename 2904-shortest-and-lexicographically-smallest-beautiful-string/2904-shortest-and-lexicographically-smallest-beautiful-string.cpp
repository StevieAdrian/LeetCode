class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        unordered_map<string, int> mpp;
        string temp;

        for (int i = 0; i < s.size(); i++) {
            temp = "";
            int count = 0;
            bool flag = false;
            for (int j = i; j < s.size(); j++) {
                temp += s[j];
                if (s[j] == '1') {
                    count++;
                }

                if (count >= k) {
                    flag = true;
                    break;
                }
            }
            if (flag == true) {
                mpp[temp] = temp.length();
            }
        }

        for (auto p: mpp) {
            cout << p.first << " -> " << p.second << endl;
        }

        vector<pair<string, int>> temp2(mpp.begin(), mpp.end());
        sort(temp2.begin(), temp2.end(), [](auto a, auto b) {
            if (a.second != b.second) {
                return a.second < b.second;
            }
            
            return a.first < b.first;
        });

        string ans = "";
        if (!temp2.empty()) {
            ans = temp2[0].first;
        }

        return ans;
    }
};