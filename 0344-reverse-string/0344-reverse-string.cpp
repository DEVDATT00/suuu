// this solve using recursion and also loop 
// class Solution {
// public:
//     void reverseString1(vector<char>& s , int st , int e){
//         if(st >= e){
//             return ;
//         }
//         swap(s[st],s[e]);
//         reverseString1(s , st + 1  , e - 1);
//     }
//     void reverseString(vector<char>& s) {
//         int st = 0 ; 
//         int e = s.size() - 1;
//         reverseString1(s , st , e);
//     }
// };



class Solution {
public:
    void reverseString(vector<char>& s) {
        int st = 0;
        int e = s.size()-1;
        while(st<e){
            swap(s[st++],s[e--]);
        }
    }
};