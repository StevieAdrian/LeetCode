class Solution {
public:
    vector<int> plusOne(vector<int>& n) {
        for (int i = n.size()-1; i >= 0; i--){
            if (n[i] < 9)  {
                n[i] += 1;
                return {n};
            }

            n[i] = 0;
        }

        n.insert(n.begin(), 1);

        return {n};
    }
};