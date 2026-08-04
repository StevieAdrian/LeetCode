class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int minn = nums[0];
        int maxx = nums[nums.size() - 1];

        unordered_map<int, int> mapp;
        for (auto p: nums) {
            mapp[p]++;
        }

        vector<int> ans;
        for (int i = minn; i <= maxx; i++) {
            if (!mapp.contains(i)){
                ans.push_back(i);
            }
        }

        return {ans};
    }
};