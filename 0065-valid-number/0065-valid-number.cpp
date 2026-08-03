class Solution {
public:
    bool isNumber(string s) {
        bool digitSeen = false;
        bool dotSeen = false;
        bool eSeen = false;
        bool digitAfterE = true;

        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                digitSeen = true;
                if (eSeen)
                    digitAfterE = true;
            }
            else if (s[i] == '+' || s[i] == '-') {
                if (!(i == 0 || s[i - 1] == 'e' || s[i - 1] == 'E'))
                    return false;
            }
            else if (s[i] == '.') {
                if (dotSeen || eSeen)
                    return false;
                dotSeen = true;
            }
            else if (s[i] == 'e' || s[i] == 'E') {
                if (eSeen || !digitSeen)
                    return false;

                eSeen = true;
                digitAfterE = false;
            }

            else {
                return false;
            }
        }

        return digitSeen && digitAfterE;
    }
};