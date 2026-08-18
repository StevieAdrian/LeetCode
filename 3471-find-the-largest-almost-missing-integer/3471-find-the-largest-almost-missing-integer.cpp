class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int maxx = -1;
        
        for (int i = 0; i + k <= nums.size(); i++) {
            for (int j = i; j < i+k; j++) {
                mp[nums[j]]++;
                maxx = max(maxx, nums[j]);
            }
        }
        
        int ans = -1;
        for (auto &p: mp) {
            // cout << p.second << endl;
            if (p.second == 1) {
                ans = max(ans, p.first);
            }
        }

        if (k == nums.size()) {
            return maxx;
        }

        return ans;
    }
};