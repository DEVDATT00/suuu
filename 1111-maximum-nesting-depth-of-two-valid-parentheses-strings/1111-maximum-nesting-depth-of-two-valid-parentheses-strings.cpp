class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int>ans;
        int c = 0;
        for(char s : seq){
            if(s == '('){
                ans.push_back(c % 2);
                c++;
            }else{
                c--;
                ans.push_back(c % 2);
            }
        }
        return ans;
    }
};