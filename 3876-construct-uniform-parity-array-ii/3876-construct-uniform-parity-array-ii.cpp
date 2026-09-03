class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int minn = *min_element(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++){
            if ((nums[i] % 2) != minn % 2 && (nums[i] - minn) % 2 != minn % 2) {
                return false;
            }
        }

        return true;
    }
};