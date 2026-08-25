class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> hs(nums.begin(), nums.end());
        int temp = k;
        while(hs.contains(temp)) {
            temp += k;
        }

        return temp;
    }
};