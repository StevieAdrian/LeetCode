class Solution {
public:
    int arrayPairSum(vector<int>& n) {
        sort(n.begin(), n.end());

        int maxx = 0;

        for (int i = 0; i < n.size(); i += 2) {
            maxx += n[i];
        }

        return maxx;
    }
};