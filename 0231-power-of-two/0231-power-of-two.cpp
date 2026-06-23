class Solution {
private:
    bool check(int n , int t){
        if(pow(2,t) > n){
            return false;
        }
        if(pow(2,t) == n){
            return true;
        }
        return check(n , t + 1);
    }
public:
    bool isPowerOfTwo(int n) {
        return check(n , 0);
    }
};