class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        for(int i = 2 ; i < n ; i++){
            string tem ;
            while(n > 2){
                tem.push_back(n % i);
                n = n / i;
            }
            int s = 0;
            int e = tem.length();
            while(s < e){
                if(s != e){
                    return false;
                }
            }
        }
        return true;
    }
};