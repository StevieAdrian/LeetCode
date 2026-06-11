class Solution {
public:
    const long long MOD = 1e9 + 7;

    int dfs(int node, int parent, vector<vector<int>>& adj) {
        int depth = 0;

        for (int next : adj[node]){
            if (next == parent) {
                continue;
            }

            depth = max(depth, dfs(next, node, adj));
        }

        return depth + 1;
    }

    long long modPow(long long base, long long exp) {
        long long res = 1;

        while (exp > 0) {
            if (exp & 1) {
                res = (res * base) % MOD;
            }

            base = (base * base) % MOD;
            exp >>= 1;
        }

        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int maxx = 0;

        for (auto& e : edges) {
            maxx = max(maxx, max(e[0], e[1]));
        }

        vector<vector<int>> adj(maxx + 1);

        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int maxxx = dfs(1, -1, adj);
        int dp = maxxx - 1;

        if (dp == 0) {
            return 0;
        }

        return modPow(2, dp - 1);
    }
};