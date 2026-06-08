class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> lesss;
        vector<int> greaterr;
        vector<int> eq;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++){
            if (nums[i] < pivot) {
                lesss.push_back(nums[i]);
            } else if (nums[i] > pivot) {
                greaterr.push_back(nums[i]);
            } else {
                eq.push_back(nums[i]);
            }
        }

        ans.insert(ans.end(), lesss.begin(), lesss.end());
        ans.insert(ans.end(), eq.begin(), eq.end());
        ans.insert(ans.end(), greaterr.begin(), greaterr.end());

        return ans;
    }
};