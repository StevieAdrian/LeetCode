class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> pref(nums.size());
        vector<int> suff(nums.size());
        pref[0] = nums[0];
        suff[nums.size() - 1] = nums[nums.size() - 1];

        for (int i = nums.size() - 2; i >= 0; i--) {
            suff[i] = min(nums[i], suff[i+1]);
        }

        for (int i = 1; i < nums.size(); i++) {
            pref[i] = max(nums[i], pref[i-1]);
        }

        for (int i = 0; i < nums.size(); i++){
            if (pref[i] - suff[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};