class Solution {
public:
    bool isPalindrome(int x) {
        int temp = x;
        long long int rev = 0;

        while (temp != 0) {
            rev = rev * 10 + temp % 10;
            temp /= 10;
        }

        if (rev == x && rev >= 0) {
            return true;
        }

        return false;
    }
};