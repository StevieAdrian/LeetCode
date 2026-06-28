class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(), nums.end(), greater<>());

        long long ans = 0;
        for (int i = 0; i < k; i++) {
            long long int temp = nums[i] * (long long)mul;
            if (mul <= 0) {
                ans += nums[i];
            } else {
                ans += temp;
            }
            mul--;
        }

        return ans;
    }
};