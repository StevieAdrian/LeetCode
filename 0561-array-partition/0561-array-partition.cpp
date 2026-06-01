class Solution {
public:
    int arrayPairSum(vector<int>& n) {
        sort(n.begin(), n.end());

        int lenp = n.size() / 2;
        int maxx = 0;

        for (int i = 0; i < n.size(); i++) {
            if (i % 2 == 0){
                maxx += n[i];
            }
        }

        return maxx;
    }
};