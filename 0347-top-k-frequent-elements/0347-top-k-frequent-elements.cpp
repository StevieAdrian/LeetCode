class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }
        
        vector<pair<int, int>> temp(mpp.begin(), mpp.end());
        sort(temp.begin(), temp.end(), [](auto a, auto b) {
            return a.second > b.second;
        });

        for (int i = 0; i < k; i++){
            ans.push_back(temp[i].first);
        }

        return ans;
    }
};