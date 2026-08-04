class Solution {
public:
    bool hasAlternatingBits(int n) {
        int first = n % 2;
        n /= 2;
        while(n > 0){
            int tem = n % 2;
            if(first == tem)
                return false;
            first = tem;
            n /= 2;
        }
        return true;
    }
};