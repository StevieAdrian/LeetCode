class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int ctr = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1){
                ctr += nums[i];
            } else {
                break;
            }
        } 

        sort(nums.begin(), nums.end());
        while (binary_search(nums.begin(), nums.end(), ctr)){
            ctr++;
        }
        
        return ctr;
    }
};