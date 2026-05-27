class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> mapp;
        unordered_set<char> lower, upper, valid, invalid;

        for (int i = 0; i < word.size(); i++) {
            mapp[word[i]]++;
            if (islower(word[i])) {
                lower.insert(word[i]);
            } else {
                upper.insert(word[i]);
            }

            if (mapp.find(tolower(word[i])) != mapp.end() && mapp.find(toupper(word[i])) != mapp.end()) {
                // debug(lower);
                if (isupper(word[i]) && lower.count(tolower(word[i])) && !invalid.count(tolower(word[i]))) {
                    valid.insert(tolower(word[i]));
                }

                if (islower(word[i]) && upper.count(toupper(word[i]))) {
                    valid.erase(word[i]);
                    invalid.insert(word[i]);
                }
            }
        }

        return valid.size();
    }
};