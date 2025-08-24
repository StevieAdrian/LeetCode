class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> n;
    
        for (int i = 0; i< nums.size(); i++){
            int m = target-nums[i];
            if (n.find(m) != n.end()){
                return {n[m], i};
            }
            n[nums[i]] = i;
        }
        return {};
    }
};