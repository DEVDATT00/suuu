class Solution {
    int mx(int index , int first , int second , int third , int n){
        if(n == index)
            return first+second+third;
        return mx(index + 1, second , third , first + second + third , n);
    }
public:
    int tribonacci(int n) {
        if(n == 0)
            return 0;
        if( n == 1 || n == 2)
            return 1;
        return mx(3,0,1,1,n);
    }
};