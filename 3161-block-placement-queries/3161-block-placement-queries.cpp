class Solution {
public:
    vector<int> bt;
    void update(int x, int v) {
        while (x < bt.size()) { bt[x] = max(bt[x], v); x += x & -x; }
    }
    int query(int x) {
        int res = 0;
        while (x > 0) { res = max(res, bt[x]); x -= x & -x; }
        return res;
    }
    
    vector<bool> getResults(vector<vector<int>>& queries) {
        int mx = 50000; 
        set<int> st = {0, mx};
        
        for (auto& q : queries) {
            if (q[0] == 1) {
                st.insert(q[1]);
            } 
        }

        bt.assign(mx + 1, 0); 
        int pre = 0;
        
        for (int x : st) { 
            if (x > 0)  {
                update(x, x - pre); 
                pre = x; 
            }
        }
        
        vector<bool> ans;
        for (int i = queries.size() - 1; i >= 0; --i) {
            if (queries[i][0] == 1) {
                int x = queries[i][1]; st.erase(x);
                auto it = st.lower_bound(x);
                int nxt = *it, pr = *(--it);
                update(nxt, nxt - pr);
            } else {
                int x = queries[i][1], sz = queries[i][2];
                auto it = st.upper_bound(x); int pr = *(--it);
                ans.push_back(max(x - pr, query(pr)) >= sz);
            }
        }
        reverse(ans.begin(), ans.end()); return ans;
    }
};