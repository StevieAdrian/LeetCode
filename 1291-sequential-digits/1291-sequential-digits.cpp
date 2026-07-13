class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";

        vector<int> ans;
        int temp = 0;
        int lowSize = to_string(low).size();
        int highSize = to_string(high).size();

        for (int i = lowSize; i <= highSize; i++) {
            for (int j = 0; j + i <= s.size(); j++) {
                int num = stoi(s.substr(j, i));

                if (num >= low && num <= high) {
                    ans.push_back(num);
                }
            }
        }

        return ans;
    }
};