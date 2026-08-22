class Solution {
public:
    bool checkDivisibility(int n) {
        int nt = n;
        int sum = 0;
        int mul = 1;
        while (nt != 0) {
            int temp = nt % 10;
            sum += temp;
            mul *= temp;
            nt /= 10;
        }

        if (n % (mul + sum) == 0) {
            return true;
        }

        return false;
    }
};