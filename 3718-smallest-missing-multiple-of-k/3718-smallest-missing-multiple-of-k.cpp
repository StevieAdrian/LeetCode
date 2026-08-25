class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> hs(nums.begin(), nums.end());
        int i = 1;
        while(true) {
            if (i % k == 0 && !hs.contains(i)) {
                return i;
            }
            i++;
        }
    }
};