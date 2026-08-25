class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> hs(nums.begin(), nums.end());
        int temp = k;
        while(find(hs.begin(), hs.end(), temp) != hs.end()) {
            temp += k;
        }

        return temp;
    }
};