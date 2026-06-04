class Solution {
public:
    int totalWaviness(int n, int m) {
        int sum = 0;
        for (int i = n; i <= m; i++){
            // int left =
            // int middle = (i / 10)%10;
            string ns = to_string(i);
            for (int j = 1; j < ns.size() - 1; j++){
                if ((ns[j] > ns[j-1] && ns[j] > ns[j+1]) || (ns[j] < ns[j-1] && ns[j] < ns[j+1])) {
                    sum++;
                }
            }
            // debug(ns);
            // if (i > 100) {
                
            // } 
        }

        return sum;
    }
};