class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 1000 && i == 1) {
                return i;
            }

            int dig = nums[i] % 10;
            if (nums[i] < 100 && nums[i] / 10 + dig == i){
                return i;
            } else if (nums[i] % 10 + ((nums[i] / 10) % 10) + (nums[i] / 100) == i) {
                return i;
            }
        }

        return -1;
    }
};