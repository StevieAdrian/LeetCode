class Solution {
public:
    double findMaxAverage(vector<int>& n, int k) {
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += n[i];
        }

        double maxx = (double)sum / k;
        for (int i = k, j = 0; i < n.size(); i++, j++) {
            sum = sum - n[j] + n[i];
            double avg = (double)sum / k;
            maxx = max(maxx, avg);
        } 

        return maxx;
    }
};