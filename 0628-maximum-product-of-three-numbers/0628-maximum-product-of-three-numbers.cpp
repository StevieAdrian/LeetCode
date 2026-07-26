class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = -1000, max2 = -1000, max3 = -1000;
        int min1 = 0, min2 = 0;

        for(auto p : nums){
            if (max1 <= p){
                max3 = max2;
                max2 = max1;
                max1 = p;
            } else if (max2 <= p){
                max3 = max2;
                max2 = p;
            } else if (max3 <= p){
                max3 = p;
            }

            if (min1 >= p){
                min2 = min1;
                min1 = p;
            } else if (min2 >= p){
                min2 = p;
            }
        }

        return max(
            max1 * max2 * max3,
            min1 * min2 * max1
        );
    }
};