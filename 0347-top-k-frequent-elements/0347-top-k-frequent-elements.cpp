class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        vector<vector<int>> bucket(nums.size()+1);

        for (auto p: mp) {
            bucket[p.second].push_back(p.first);
        }

        vector<int> result;
        for (int i = bucket.size() - 1; i >= 0 && k > 0; i--) {
            for (auto num: bucket[i]) {
                result.push_back(num);
                k--;
                if (k == 0) break;
            }
        }
        /*
            1, 1, 1, 1, 2, 3, 3
            bucket[4] = 1
            bucket[1] = 2
            bucket[2] = 3
            
            print from biggest bucket size
        */
        return result;
    }
};
