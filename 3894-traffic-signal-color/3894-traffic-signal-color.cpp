class Solution {
public:
    string trafficSignal(int timer) {
        if(timer <= 90 && timer > 30){
            return "Red";
        }else if(timer == 0){
            return "Green";
        }else if(timer == 30){
            return "Orange";
        }
        return "Invalid";
    }
};