class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int temp = k;
        while(find(nums.begin(), nums.end(), temp) != nums.end()) {
            temp += k;
        }

        return temp;
    }
};