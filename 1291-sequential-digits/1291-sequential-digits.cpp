class Solution {
public:
    int gets(int n){
        return to_string(n).length();
    }
    vector<int> sequentialDigits(int low, int high) {
        string st = "123456789";
        vector<int>r;
        string tem;
        int t ;
        int save = gets(low);
        for( ; save <= gets(high) ; save++){
            for(int i = 0 ; i <= (int)st.length()-save ; i++){
                tem = st.substr(i,save);
                t = stoi(tem);
                if(t >= low && t <= high){
                    r.push_back(t);
                }
            }
        }
        return r;
    }
};