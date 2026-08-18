class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if (k == nums.size()) {
            return *max_element(nums.begin(), nums.end());
        }

        unordered_map<int, int> mp;
        unordered_map<int, int> count;

        for (int i = 0; i + k <= nums.size(); i++) {
            mp.clear();
            for (int j = i; j < i+k; j++) {
                mp[nums[j]]++;
            }

            for (auto p: mp) {
                count[p.first]++;
            }
        }
        
        int ans = -1;
        for (auto p: count) {
            cout << p.second << endl;
            if (p.second == 1) {
                ans = max(ans, p.first);
            }
        }

        return ans;
    }
};