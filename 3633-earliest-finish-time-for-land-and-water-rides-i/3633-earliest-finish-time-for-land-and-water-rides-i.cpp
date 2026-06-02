class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        vector<int> suml(ls.size());
        vector<int> sumw(ws.size());
        int minn = INT_MAX;
        int sum = 0;

        for (int i = 0; i < ls.size(); i++){
            for (int j = 0; j < ws.size(); j++) {
                int l = ls[i] + ld[i];
                
                if (l >= ws[j]) {
                    sum = l + wd[j];
                } else {
                    sum = ws[j] + wd[j];
                }
                
                minn = min(minn, sum);
                
                int w = ws[j] + wd[j];
                if (w > ls[i]) {
                    sum = w + ld[i];
                } else {
                    sum = ls[i] + ld[i];
                }

                minn = min(minn, sum);
            }
        }

        return minn;
    }
};