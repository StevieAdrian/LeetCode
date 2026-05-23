class Solution {
public:
    int floyd(int n) {
        int count = 0;

        while (n != 0) {
            int temp = n % 10;    
            n /= 10;
            count += temp*temp;
        }

        return count;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        while (true) {
            slow = floyd(slow);
            fast = floyd(floyd(fast));
            
            if (fast == 1) {
                return true;
            }

            if (slow == fast) {
                return false;
            }
        }

        return true;
    }

};