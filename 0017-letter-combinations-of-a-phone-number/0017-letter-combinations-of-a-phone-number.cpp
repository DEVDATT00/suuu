class Solution {
    void devdatt(string digits,vector<string>&ans,vector<string>&findout,string& output,int index){
        if(index == digits.length()){
            ans.push_back(output);
            return;
        }
        int tem = digits[index] - '0';
        for(int i = 0 ; i < findout[tem].length() ; i++){
            output.push_back(findout[tem][i]);
            devdatt(digits,ans,findout,output,index+1);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        vector<string>findout = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string output;
        devdatt(digits,ans,findout,output,0);
        return ans;
    }
};