class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
    
        int top = 0, left = 0;
        int bottom = matrix.size() - 1;
        int right = matrix[0].size() - 1;
        // debug(right); debug(bottom);
        // debug(matrix[0][0]);

        // cout << bottom << right << endl;
        while (top <= bottom && left <= right){
            for (int i = left; i <= right; i++){
                // debug(top);
                ans.push_back(matrix[top][i]);
                // debug(matrix[top][i]);
            }
            top++;
            // debug(ans);
            
            // if (bottom > top) {
            for (int i = top; i <= bottom; i++){
                ans.push_back(matrix[i][right]);
                // debug(matrix[i][right]);
            }
            right--;
            // }
            // debug(ans);

            // debug(right); debug(left);
            if (top <= bottom){
                for (int i = right; i >= left; i--){
                    ans.push_back(matrix[bottom][i]);
                    // debug(matrix[bottom][i]);
                }
                bottom--;
            }
            // debug(ans);

            if (left <= right){
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                    // debug(matrix[i][left]);
                }
                left++; 
            }
            // debug(ans);
            // top++;
        }

        return {ans};
    }
};