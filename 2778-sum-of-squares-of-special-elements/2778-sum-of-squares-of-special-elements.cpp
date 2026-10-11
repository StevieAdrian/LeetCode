class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sum = 0;
        for (int i = 1; i <= nums.size(); i++) {
            int mult = 0;
            if (nums.size() % i == 0) {
                mult = nums[i-1] * nums[i-1];
            }

            cout << mult << endl;
            sum += mult;
        }

        return sum;
    }
};