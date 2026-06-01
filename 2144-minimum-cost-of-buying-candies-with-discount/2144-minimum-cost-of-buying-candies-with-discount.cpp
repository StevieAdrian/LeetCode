class Solution {
public:
    int minimumCost(vector<int>& n) {
        sort(n.begin(), n.end(), greater<int>());

        int sum = 0;
        for (int i = 0; i < n.size(); i++){
            if (i % 3 != 2) { 
                sum += n[i];
            }
        }

        return sum;
    }
};