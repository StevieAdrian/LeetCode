class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxx = INT_MIN;
        int curr = 0;
        for (int i = 0; i < gain.size(); i++) {
            maxx = max(maxx, curr); 
            curr = curr + gain[i];
        }

        maxx = max(maxx, curr);
        return maxx;
    }
};