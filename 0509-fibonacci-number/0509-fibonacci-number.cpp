// class Solution {
// public:
//     int fibo(int n){
//         if(n == 0){
//             return 0;
//         }
//         if(n == 1){
//             return 1;
//         }
//         return fibo(n-1) + fibo(n-2);
//     }
//     int fib(int n) {
//         return fibo(n);
//     }
// };



// class Solution {
// public:
//     int fib(int n) {
//         if(n == 0){
//             return 0;
//         }else if(n == 1){
//             return 1;
//         }
//         return fib(n - 1) + fib(n - 2);
//     }
// };

class Solution{
private:
    int f(int n , vector<int>&d){
        if(n == 0 || n == 1 ){
            return n;
        }
        if(d[n] != -1){
            return d[n];
        }
        d[n] = f(n-1 , d)+f(n-2,d);
        return d[n];
    }
public:
    int fib(int n){
        vector<int>d(n+1 , -1);
        return f(n , d);
    }
};