class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0, r = 0;
        vector<int> cnt(3, 0);
        int sum = 0;

        while (r < s.size()) {
            char temp = s[r];
            cnt[temp - 'a']++;

            while (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {
                sum += s.size() - r;
                cout << sum << endl;

                char temp2 = s[l];
                cnt[temp2 - 'a']--;
                l++;
            }
            r++;
        }

        return sum;
    } 
};