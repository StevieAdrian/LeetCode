class Solution {
public:
    int minElement(vector<int>& n) {
        int minn = INT_MAX;

        for (int i = 0; i < n.size(); i++){
            int count = 0;
            while (n[i] != 0) {
                count += n[i] % 10;
                n[i] /= 10;
            }
            minn = min(minn, count);
        }

        return minn;
    }
};