class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& n) {
        vector<vector<int>> ans;
        sort(n.begin(), n.end());
        
        for (int i = 0; i < n.size(); i++){
            int l = i+1, r = n.size() - 1;

            if (i > 0 && n[i] == n[i-1]) continue;
            if (i != r) l = i + 1;
            
            // if (n[i] == 0 && n[l] == 0 && n[r] == 0){
            //     return {{0, 0, 0}};
            // }

            // debug(i); debug(l); debug(r);

            while (l < r){
                if (n[i] + n[l] + n[r] < 0) {
                    l++;
                } else if (n[i] + n[l] + n[r] > 0){
                    r--;
                } else {
                    ans.push_back({n[i], n[l], n[r]});
                    
                    while (l < r && n[l] == n[l+1]) l++;
                    while (l < r && n[r] == n[r-1]) r--;

                    l++;
                    r--; 
                }
                // debugArr(n[l]);
            }
            
        }

        return {ans};
    }
};