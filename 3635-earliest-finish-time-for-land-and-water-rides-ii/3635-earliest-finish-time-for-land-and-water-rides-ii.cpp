class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int l = INT_MAX;
        for (int i = 0; i < ls.size(); i++) {
            l = min(l, ls[i] + ld[i]);
        }

        int land_water = INT_MAX;
        for (int i = 0; i < ws.size(); i++) {
            land_water = min(
                land_water,
                max(ws[i], l) + wd[i]
            );
        }

        int w = INT_MAX;
        for (int i = 0; i < ws.size(); i++) {
            w = min(w, ws[i] + wd[i]);
        }

        int water_land = INT_MAX;
        for (int i = 0; i < ls.size(); i++) {
            water_land = min(
                water_land,
                max(ls[i], w) + ld[i]
            );
        }

        return min(land_water, water_land);
    }
};