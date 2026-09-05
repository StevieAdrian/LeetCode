class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> suff(nums.size() + 1);
        suff[nums.size() - 1] = nums[nums.size() - 1];

        for (int i = nums.size() - 2; i >= 0; i--) {
            suff[i] = min(suff[i+1], nums[i]);
        }
        
        int maxx = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            maxx = max(maxx, nums[i]);
            if (maxx - suff[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};