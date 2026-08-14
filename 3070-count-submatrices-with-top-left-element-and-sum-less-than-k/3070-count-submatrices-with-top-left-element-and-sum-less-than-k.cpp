class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> pref(m);
        int ctr = 0, curr = 0;

        for (int i = 0; i < n; i++){
            curr = 0;
            for (int j = 0; j < m; j++) {
                pref[j] += grid[i][j];
                curr += pref[j];
                if (curr <= k) {
                    ctr++;
                }
            }
        }

        return ctr;
    }
};