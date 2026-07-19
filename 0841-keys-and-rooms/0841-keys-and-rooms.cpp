class Solution {
    void justdothis(vector<vector<int>>&rooms,vector<bool>&check,int t){
        if(check[t]){
            return;
        }
        check[t] = true;
        for(int i = 0 ; i < rooms[t].size() ; i++){
            justdothis(rooms,check,rooms[t][i]);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool>check(rooms.size(),false);
        justdothis(rooms,check,0);
        for(int i = 0 ; i < check.size() ; i++){
            if(!check[i]){
                return false;
            }
        }
        return true;
    }
};