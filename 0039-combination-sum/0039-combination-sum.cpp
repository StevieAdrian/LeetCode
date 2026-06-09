class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(vector<int>& n, int target, int start) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }

        if (target < 0) {
            return;
        }

        for (int i = start; i < n.size(); i++) {
            path.push_back(n[i]);
            dfs(n, target - n[i], i);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& n, int target) {
        dfs(n, target, 0);
        return ans;
    }
};