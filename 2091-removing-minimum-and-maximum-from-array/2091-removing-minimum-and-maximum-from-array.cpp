class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        auto mxx = max_element(nums.begin(), nums.end());
        auto minn = min_element(nums.begin(), nums.end());
        
        int front = max(mxx - nums.begin(), minn - nums.begin()) + 1;
        int back = nums.size() - min(mxx - nums.begin(), minn - nums.begin());
        int mid = min(mxx - nums.begin(), minn - nums.begin()) + 1 + nums.size() - max(mxx - nums.begin(), minn - nums.begin());

        return min({mid, front, back});
    }
};