class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int count ;
        vector<int>s;
        vector<int>ans;
        vector<int>index;
        for(int i = 0 ; i < mat.size() ; i++){
            count = 0;
            for(int j = 0 ; j < mat[i].size() ; j++){
                if(mat[i][j] == 0){
                    break;
                }
                count++;
            }
            s.push_back(count);
            index.push_back(i);
        }
        int mini;
        for(int i = 0 ; i < s.size() - 1 ; i++){
            mini = i;
            for(int j = i + 1 ; j < s.size() ; j++){
                if(s[j] < s[mini] || (s[j] == s[mini] && index[j] < index[mini])){
                    mini = j;
                } 
            }
            swap(s[i] , s[mini]);
            swap(index[i], index[mini]);
        }
        for(int i = 0 ; i < k ; i++){
            ans.push_back(index[i]);
        }
        return ans;
    }
};