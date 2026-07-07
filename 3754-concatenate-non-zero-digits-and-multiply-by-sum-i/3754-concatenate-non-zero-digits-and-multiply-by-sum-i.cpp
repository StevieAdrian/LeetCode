class Solution {
public:
    long long sumAndMultiply(int n) {
        string temp = to_string(n);
        long long ans = 0;
        long long x;

        for (int i = 0; i < temp.size(); i++) {
            long long curr = temp[i] - '0';
            ans += curr;
            if (curr != 0) {
                x = x * 10 + curr;
            }
        }

        return ans * x;
    }
};