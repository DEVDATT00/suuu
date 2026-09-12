class Solution {
public:
    void par(int n , int op , int cl , vector<string>& ans , string ch ){
        if(cl == n){
            ans.push_back(ch);
            return;
        }
        if(op < n){
            par(n,op+1,cl,ans,ch+"(");
        }
        if(cl < op){
            par(n,op,cl+1,ans,ch+")");
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        par(n,0,0,ans,"");
        return ans;
    }
};