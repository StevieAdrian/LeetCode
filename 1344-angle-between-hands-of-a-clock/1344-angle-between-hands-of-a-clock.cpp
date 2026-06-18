class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hrs = hour*30;
        double min = minutes*0.5;
        // debug(hrs); debug(min);
        
        double hand = minutes * 6;
        // debug(hand);
        double ans = abs(hrs + min - hand);

        if (ans >= 180) {
            return 360 - ans;
        } 

        return ans;
    }
};