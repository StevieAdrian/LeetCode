struct TrieNode {
    int child[26];
    int minn;
    int idx;
};

TrieNode pool[3000000];
int poolSize = 0;

class Solution {
public:
    int newNode() {
        pool[poolSize].minn = INT_MAX;
        pool[poolSize].idx = INT_MAX;
        fill(pool[poolSize].child, pool[poolSize].child + 26, -1);
        return poolSize++;
    }

    void insert(int root, string& s, int idx) {
        int node = root;
        int n = s.size();

        if (n < pool[node].minn) {
            pool[node].minn = n;
            pool[node].idx = idx;
        }

        for (int i = n-1; i >= 0; i--){
            int c = s[i] - 'a';

            if (pool[node].child[c] == -1){
                pool[node].child[c] = newNode();
            }

            node = pool[node].child[c];

            if (n < pool[node].minn) {
                pool[node].minn = n;
                pool[node].idx = idx;
            }
        }
    }

    vector<int> stringIndices(vector<string>& container, vector<string>& query) {
        int root = newNode();

        for (int i = 0; i < container.size(); i++){
            insert(root, container[i], i);
        }

        vector<int> ans;

        for (auto& quer: query) {
            int node = root;

            for (int i = quer.size() - 1; i >= 0; i--){
                int c = quer[i] - 'a';

                if (pool[node].child[c] != -1){
                    node = pool[node].child[c];
                } else {
                    break;
                }
            }

            ans.push_back(pool[node].idx);
        }

        return ans;
    }
};