class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int row = mat.size();
        int col = mat[0].size();
        
        if (mat == target) {
            return true;
        }
        
        vector<vector<int>> temp(row, vector<int>(col));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++){
                temp[i][j] = mat[row-j-1][i];
            }
        }

        mat = temp;

        if (mat == target) {
            return true;
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++){
                temp[i][j] = mat[row-j-1][i];
            }
        }

        mat = temp;

        if (mat == target) {
            return true;
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++){
                temp[i][j] = mat[row-j-1][i];
            }
        }

        mat = temp;

        if (mat == target) {
            return true;
        }

        return false;
    }
};