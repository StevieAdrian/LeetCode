class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++) {
            if (mpp.contains(target - nums[i])) {
                return {mpp.find(target-nums[i])->second, i};
            }
            
            mpp[nums[i]] = i;
        }

        return { };
    }
};