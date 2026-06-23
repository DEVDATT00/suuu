// i solve it with recursion and also with looping 
// class Solution {
// public:
//     bool isPalindrome(string st , int s , int e) {
//         if(s > e){
//             return true;
//         }
//         if(st[s] != st[e]){
//             return false;
//         }
//         return isPalindrome( st ,  s + 1 ,  e - 1);
//     }
//     bool isPalindrome(int x) {
//         string st = to_string(x);
//         int s = 0 ;
//         int e = st.length() - 1;
//         return isPalindrome( st ,  s ,  e );
//     }
// };



class Solution {
public:
    bool isPalindrome(int x) {
        string st = to_string(x);
        int s = 0 ;
        int e = st.length() - 1;
        while(s <= e){
            if(st[s++] != st [e--]){
                return 0;
            }
        }
        return 1;
    }
};