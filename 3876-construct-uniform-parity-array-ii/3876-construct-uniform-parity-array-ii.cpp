class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int minn = nums[0];

        for (int i = 1; i < nums.size(); i++){
            if ((nums[i] % 2) != minn % 2 && (nums[i] - minn) % 2 != minn % 2) {
                return false;
            }
        }

        return true;
    }
};