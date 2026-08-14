class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l = 0, r = s.size() - 1;
        unordered_map<char, int> mapp;
        int count = 0;
        int maxx = INT_MIN;
        int dbg = 0;

        while (l <= r) {
            int temp = l + 1;
            // count = 0;
            mapp.clear(); 
            // cout << dbg << " s: " << s[dbg] << endl;

            for (int i = l; i < temp; i++) {
                // cout << "l: " << l << " temp: " << temp << endl;
                mapp[s[i]]++;
                if (mapp[s[i]] > 2 || temp > s.size()) {
                    break;
                }

                count++;
                // cout << "l: " << l << " temp: " << temp << " count: " << count << endl;
                // cout << count << endl;
                temp++;
            }

            maxx = max(count, maxx);
            count = 0;
            dbg++;
            l++;
            // r--;
        }
        
        return maxx;
    }
};