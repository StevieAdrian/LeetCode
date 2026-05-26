class Solution {
public:
    int numberOfSpecialChars(string s) {
        unordered_map<char, int> mapp;

        for (int i = 0; i < s.size(); i++){
            mapp[s[i]]++;
        }

        int count = 0;
        for (auto p: mapp){
            char c = p.first;
            // debug(c);
            if (mapp.find(tolower(c)) != mapp.end() && mapp.find(toupper(c)) != mapp.end()) {
                // debug("hi");
                if (isupper(c)) {
                    count++;
                }
            }
        }

        return count;
    }
};