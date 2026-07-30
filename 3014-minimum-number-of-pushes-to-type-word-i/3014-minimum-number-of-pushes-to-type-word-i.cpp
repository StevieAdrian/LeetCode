class Solution {
public:
    int minimumPushes(string word) {
        int cnt = 0;
        int mark = 1;
        for (int i = 1; i <= word.length(); i++) {
            cnt += mark;
            if (i % 8 == 0) {
                mark++;
            }
        }

        return cnt;
    }
};