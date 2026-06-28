class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int,int>m;
        for(char c : magazine){
            m[c]++;
        }
        for(char d : ransomNote){
            if(m[d] == 0){
                return false;
            }
            m[d]--;
        }
        return true;
    }
};