class Solution {
public:
    int maxDepth(string s) {
        int mx = 0;
        int count = 0;
        for(char c : s){
            if(c != '(' && c != ')')
                continue;
            if(c == '(')
                count++;
            if(c ==')'){
                mx = max(mx , count);
                count--;
            }
        }
        return mx;
    }
};