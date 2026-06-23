// // this is solve using recursion and also solve with normal method
// class Solution {
// public:
//     string reverse1(string s , int i , int j){
//         if(i > j){
//             return s;
//         }
//         swap(s[i++],s[j--]);
//         return reverse1(s , i , j);
//     }
//     int reverse(int x) {
//         string s = to_string(x);
//         int i = 0 , j = s.length() - 1; 
//         if(x < 0){
//             int y = stoi(reverse1(s , i , j));
//             return y * -1;
//         }
//         return stoi(reverse1(s , i , j));
//     }
// };

class Solution {
public:
    int reverse(int x) {
        long long dev = 0;
        long long digit;
        while(x > 0 || x < 0){
            digit = x % 10;
            x = x / 10;
            dev = dev * 10 + digit ;
            if(dev < INT_MIN || dev > INT_MAX){
                return 0;
            }
        }
        return (int)dev;
    }
};