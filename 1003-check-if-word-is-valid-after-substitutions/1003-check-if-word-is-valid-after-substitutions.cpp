class Solution {
public:
    bool isValid(string s) {
        string t = s;
        for (int i = 0; i + 2 < (int)t.length(); i++) {
            if (t[i] == 'a') {
                string tem = t.substr(i, 3);
                if (tem == "abc") {
                    t.erase(i, 3);
                    if (i >= 2)
                        i -= 3;
                    else
                        i = -1;
                }
            }
        }
        return t.empty();
    }
};