class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if (k == nums.size()) {
            return *max_element(nums.begin(), nums.end());
        }

        unordered_map<int, int> mp;

        for (int i = 0; i + k <= nums.size(); i++) {
            for (int j = i; j < i+k; j++) {
                mp[nums[j]]++;
            }
        }
        
        int ans = -1;
        for (auto &p: mp) {
            // cout << p.second << endl;
            if (p.second == 1) {
                ans = max(ans, p.first);
            }
        }

        return ans;
    }
};