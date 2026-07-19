class Solution {
    void justdothis(vector<vector<int>>&rooms,vector<bool>&check,set<int>&s,int t){
        if(check[t]){
            return;
        }
        check[t] = true;
        for(int i = 0 ; i < rooms[t].size() ; i++){
            s.insert(rooms[t][i]);
            justdothis(rooms,check,s,rooms[t][i]);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int>s;
        s.insert(0);
        vector<bool>check(rooms.size(),false);
        justdothis(rooms,check,s,0);
        for(int i = 0 ; i < check.size() ; i++){
            if(!check[i]){
                return false;
            }
        }
        return true;
    }
};