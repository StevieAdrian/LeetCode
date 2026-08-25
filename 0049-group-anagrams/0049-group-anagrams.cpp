class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < strs.size(); i++){
            // string res = sort(strs[i].begin(), strs[i].end());    
            string res = strs[i];
            sort(res.begin(), res.end());
            mp[res].push_back(strs[i]);
        }

        vector<vector<string>> res;

        for (const auto& p: mp) {
            res.push_back(p.second);
        }
        
        return res;
    }
};