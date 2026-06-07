class Solution {
public:
    int maxSubArray(vector<int>& n) {
        int sum = n[0];
        int ans = n[0];

        for (int i = 1; i <= n.size()-1; i++){
            sum = max(n[i], sum + n[i]);
            ans = max(ans, sum);        
        }

        return ans;
    }
};