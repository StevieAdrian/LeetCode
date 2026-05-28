class Solution {
public:
    int minEatingSpeed(vector<int>& n, int h) {
        int maxx = n[0];
        for (int i = 0; i < n.size(); i++){
            if (n[i] > maxx) {
                maxx = n[i];
            }
        }

        int low = 1;
        int high = maxx;
        int mid;
        int minn = maxx;

        // cout << p.size() << endl;
        while (low <= high) {
            mid = ((high - low) / 2) + low;
            // debug(mid);
            long long int k = 0;
            for (int i = 0; i < n.size(); i++){
                k += ceil((double)n[i]/mid);
                // cout << n[i] << " " << ceil(n[i]/mid) << endl;
            }
            // debug(k);
            // break;

            if (k == h) {
                minn = min(minn, mid);                
            }

            if (k <= h) {
                minn = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }

            if (low == maxx) return low;
            // if (high == maxx) return high;
            // debug(low); debug(high);
        }

        // minn = min(mid, minn);
        // debug(minn);
        return minn;
    }
};