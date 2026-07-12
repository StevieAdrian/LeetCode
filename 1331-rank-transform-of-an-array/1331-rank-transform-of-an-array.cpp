class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        unordered_map<int, int> rank;
    
        for (int i = 0, j = 1; i < temp.size(); i++) {
            if (!rank.count(temp[i])) {
                rank[temp[i]] = j++;
            }
        }

        temp.clear();
        for (auto p: arr) {
            temp.push_back(rank[p]);
        }

        return temp;
    }
};