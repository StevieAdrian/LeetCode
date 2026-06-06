class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> left;
        vector<int> right;
        vector<int> ans;

        left.push_back(0);
        right.push_back(0);

        for (int i = 0; i < nums.size() - 1; i++){
            left.push_back(left[i] + nums[i]);
        }

        for (int i = nums.size() - 1, j = 0; i > 0; i--, j++){
            right.push_back(right[j] + nums[i]);
        }

        for (int i = right.size()-1, j = 0; i >= 0; i--, j++){
            ans.push_back(abs(left[j] - right[i]));
        }
        
        return ans;
    }
};