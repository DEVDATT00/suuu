class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        int j = 0 ;
        int i = 1;
        while(j < target.size()){
            if(i < target[j]){
                ans.push_back("Push");
                ans.push_back("Pop");
            }else{
                ans.push_back("Push");
                j++;
            }
            i++;
        }
        return ans;
    }
};