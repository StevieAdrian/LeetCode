class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int cnt = 0;
        for (int i = 100; i <= 999; i++) {
            if (i % 2 == 0) {
                vector<int> temp = digits;

                int first = i / 100;
                int second = (i / 10) % 10;
                int third = i % 10;

                auto it = find(temp.begin(), temp.end(), first);
                if (it == temp.end()) continue;
                temp.erase(it);

                it = find(temp.begin(), temp.end(), second);
                if (it == temp.end()) continue;
                temp.erase(it);

                it = find(temp.begin(), temp.end(), third);
                if (it == temp.end()) continue;

                cnt++;
            }   
        }

        return cnt;
    }
};