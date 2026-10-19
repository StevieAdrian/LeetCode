class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int ctr = 0;
        int cnt = 0;

        for (int p : nums) {
            if (p == target) {
                cnt++;
            }

            if (p < target) {
                ctr++;
            }
        }


        vector<int> ans;
        for (int i = ctr; i < ctr + cnt; i++){
            ans.push_back(i);
        }

        return ans;
    }
};