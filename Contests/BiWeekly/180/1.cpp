// https://leetcode.com/problems/traffic-signal-color/

class Solution {
public:
    string trafficSignal(int timer) {
        if(timer == 0)
            return "Green";
        if(timer == 30)
            return "Orange";
        if(timer <= 90 && 30 < timer)
            return "Red";
        return "Invalid";
    }
};