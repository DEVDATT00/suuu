class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> ans;
        while(ss >> word){
            ans.push_back(word);
        }
        word = "";
        for(int i = 0 ; i < ans.size() ; i++){
            for(int j = ans[i].size()-1 ; j >= 0 ; j--){
                word.push_back(ans[i][j]);
            }
            if(i == ans.size() - 1){
                continue;
            }
            word.push_back(' ');
        }
        return word;
    }
};