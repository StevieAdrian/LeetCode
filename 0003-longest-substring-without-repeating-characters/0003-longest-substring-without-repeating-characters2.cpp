class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> n;
        int l = 0;
        int len = 0;
        
        for (int i = 0; i < s.length(); i++){
            while (n.count(s[i])){
                n.erase(s[l]);
                l++;
            }

            n.insert(s[i]);
            len = max(len, i-l+1);
        }
        
        return len;
    }
};