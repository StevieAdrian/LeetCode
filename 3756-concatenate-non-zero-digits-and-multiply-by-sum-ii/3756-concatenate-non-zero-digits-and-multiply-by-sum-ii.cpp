class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int> mpe;
        const int MOD = 1e9 + 7;
        vector<long long> perkedel(s.size() + 1, 0);;
        vector<long long> bakwan(s.size() + 1, 0);

        string t;

        for (int i = 0; i < s.size(); i++) {
            int d = s[i] - '0';

            perkedel[i + 1] = perkedel[i];
            bakwan[i + 1] = bakwan[i];

            if (d != 0) {
                perkedel[i + 1] += d;
                bakwan[i + 1]++;
                t.push_back(s[i]);
            }
        }

        int m = t.size();

        vector<long long> pawpatrol(m + 1, 1);
        for (int i = 1; i <= t.size(); i++) {
            pawpatrol[i] = (pawpatrol[i - 1] * 10) % MOD;
        }

        vector<long long> mediumgaje(m + 1, 0);
        for (int i = 0; i < m; i++) {
            mediumgaje[i + 1] = (mediumgaje[i] * 10 + (t[i] - '0')) % MOD;
        }

        for (auto p: queries) {
            int l = p[0];
            int r = p[1];

            long long sum = perkedel[r + 1] - perkedel[l];

            int ll = bakwan[l];
            int rr = bakwan[r + 1] - 1;

            if (ll > rr) {
                mpe.push_back(0);
                continue;
            }

            int len = rr - ll + 1;

            long long x = (mediumgaje[rr + 1] - (mediumgaje[ll] * pawpatrol[len]) % MOD + MOD) % MOD;
            mpe.push_back((x * sum) % MOD);
        }

        return mpe;
    }
};