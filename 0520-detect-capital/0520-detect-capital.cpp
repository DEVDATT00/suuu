class Solution {
public:
    bool detectCapitalUse(string word) {
        int countcapital = 0 ;
        for(int i = 0 ; i < word.size() ; i++){
            if(isupper(word[i])){
                countcapital++;
            }
        }
        return countcapital == word.size() || countcapital == 0 || (countcapital == 1 && isupper(word[0]));
        return false;
    }
};