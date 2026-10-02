class Solution {
public:
    int minInsertions(string s) {
        int add = 0;
        int open = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                open++;
            }
            else {
                if (i + 1 < s.length() && s[i + 1] == ')') {
                    i++;
                }
                else {
                    add++;
                }
                if (open > 0) {
                    open--;
                }
                else {
                    add++;
                }
            }
        }
        add += open * 2;
        return add;
    }
};