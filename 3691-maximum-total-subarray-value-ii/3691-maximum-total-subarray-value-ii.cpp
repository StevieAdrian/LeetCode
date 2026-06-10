class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int logn = floor(log2(nums.size())) + 1;
        vector<vector<int>> stMax(nums.size(), vector<int>(logn));
        vector<vector<int>> stMin(nums.size(), vector<int>(logn));

        for (int i = 0; i < nums.size(); i++) {
            stMax[i][0] = stMin[i][0] = nums[i];
        }

        for (int j = 1; j < logn; j++) {
            for (int i = 0; i + (1 << j) <= nums.size(); i++) {
                stMax[i][j] =
                    max(stMax[i][j - 1], stMax[i + (1 << (j - 1))][j - 1]);
                stMin[i][j] =
                    min(stMin[i][j - 1], stMin[i + (1 << (j - 1))][j - 1]);
            }
        }

        auto queryMax = [&](int l, int r) {
            int j = floor(log2(r - l + 1));
            return max(stMax[l][j], stMax[r - (1 << j) + 1][j]);
        };

        auto queryMin = [&](int l, int r) {
            int j = floor(log2(r - l + 1));
            return min(stMin[l][j], stMin[r - (1 << j) + 1][j]);
        };
        
        priority_queue<tuple<int, int, int>> pq;
        for (int l = 0; l < nums.size(); l++) {
            pq.emplace(queryMax(l, nums.size() - 1) - queryMin(l, nums.size() - 1), l, nums.size() - 1);
        }

        long long ans = 0;
        while (k--) {
            auto [val, l, r] = pq.top();
            pq.pop();
            ans += val;
            if (r > l) {
                pq.emplace(queryMax(l, r - 1) - queryMin(l, r - 1), l, r - 1);
            }
        }
        
        return ans;
    }
};