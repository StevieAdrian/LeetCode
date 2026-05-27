class Solution {
public:
    // int numberOfSpecialChars(string word) {
    //     unordered_map<char, int> mapp;
    //     unordered_set<char> lower, upper, valid, invalid;

    //     for (int i = 0; i < word.size(); i++) {
    //         mapp[word[i]]++;
    //         if (islower(word[i])) {
    //             lower.insert(word[i]);
    //         } else {
    //             upper.insert(word[i]);
    //         }

    //         if (mapp.find(tolower(word[i])) != mapp.end() && mapp.find(toupper(word[i])) != mapp.end()) {
    //             // debug(lower);
    //             if (isupper(word[i]) && lower.count(tolower(word[i])) && !invalid.count(tolower(word[i]))) {
    //                 valid.insert(tolower(word[i]));
    //             }

    //             if (islower(word[i]) && upper.count(toupper(word[i]))) {
    //                 valid.erase(word[i]);
    //                 invalid.insert(word[i]);
    //             }
    //         }
    //     }

    //     return valid.size();
    // }
    int numberOfSpecialChars(string word) {
        vector<int> lower(26, -1); // dr -1, soalny 0 tu valid index
        vector<int> upper(26, -1);

        for (int i = 0; i < word.size(); i++){
            if (islower(word[i])) {
                lower[word[i] - 'a'] = i;
            } else {
                if (upper[word[i] - 'A'] == -1){
                    upper[word[i] - 'A'] = i;
                }
            }
        }

        int count = 0;
        for (int i = 0; i < 26; i++){
            if(lower[i] != -1 && upper[i] != -1 && upper[i] > lower[i]){
                count++;
            }
        }

        return count;
    }
};