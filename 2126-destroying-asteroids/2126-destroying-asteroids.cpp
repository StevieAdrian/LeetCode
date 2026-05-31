class Solution {
public:
    bool asteroidsDestroyed(long long int mass, vector<int>& ast) {
        sort(ast.begin(), ast.end());

        for (int i = 0; i < ast.size(); i++) {
            if (mass >= ast[i]) {
                mass += ast[i];
            } else {
                return false;
            }
        }

        return true;
    }
};