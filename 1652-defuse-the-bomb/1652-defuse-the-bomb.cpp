class Solution {
    void possitive(vector<int> code , int k , vector<int> &final){
        int tem = 0;
        int n = code.size();
        for(int i = 1 ; i <= k ; i++){
            tem += code[i%n];
        }
        final.push_back(tem);
        int i = 1; 
        int j = k;
        while(final.size() != n){
            tem -= code[i%n];
            i++;
            j++;
            tem += code[j%n];
            final.push_back(tem);
        }
    }
    void negative(vector<int> &code , int &k , vector<int> &final){
        k = abs(k);
        int n = code.size();
        int tem = 0;
        int i = n - k;
        int j = n - 1;
        for(int l = 0 ; l < k ; l++){
            tem += code[i+l];
        }
        final.push_back(tem);
        while(final.size() != n){
            tem -= code[i%n];
            i++;
            j++;
            tem += code[j%n];
            final.push_back(tem);
        }
    }
public:
    vector<int> decrypt(vector<int>& code, int k) {
        // for case k = 0
        if(k == 0){
            vector<int>tem(code.size(),0);
            return tem;
        }
        vector<int>final;
        if(k > 0){
            possitive(code,k,final);
        }else{
            negative(code,k,final);
        }
        return final;
    }
};