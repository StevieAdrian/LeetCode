class Solution {
public:
    int minimumCost(vector<int>& n) {
        sort(n.begin(), n.end(), greater<int>());

        int sum = 0;
        int jump = 0;
        for (int i = 0; i < n.size(); i++){
            if (jump == 2) {
                jump = 0;
                continue;
            }
            // debug(i);
            jump++;
            cout << n[i] << endl;
            sum += n[i];
        }

        return sum;
    }
};