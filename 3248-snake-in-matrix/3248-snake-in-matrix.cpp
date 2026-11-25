class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int count = 0 ;
        for(int i = 0 ; i < commands.size() ; i++){
            if(commands[i] == "UP"){
                count = count - n ;
            }else if(commands[i] == "RIGHT"){
                count = count + 1 ;
            }else if(commands[i] == "DOWN"){
                count = count + n ;
            }else if(commands[i] == "LEFT"){
                count = count - 1;
            }
        }
        return count;
    }
};