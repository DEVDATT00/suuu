class Solution {
    bool check4(string s) {
        int i = 0;
        int count = 0;

        for (int part = 0; part < 4; part++) {
            int j = i;

            while (j < s.length() && s[j] != '.') {
                j++;
            }
            count++;
            if (i == j)
                return false;

            if (j - i > 3)
                return false;

            if (j - i > 1 && s[i] == '0')
                return false;

            for (int k = i; k < j; k++) {
                if (!isdigit(s[k]))
                    return false;
            }

            int num = stoi(s.substr(i, j - i));

            if (num > 255)
                return false;
            if (part == 3 && j < s.length())
                return false;
            i = j + 1;
        }
        return true;
    }
    bool check6(string s) {
        int i = 0;
        for (int part = 0; part < 8; part++) {
            int j = i;
            while (j < s.length() && s[j] != ':') {
                if (!((s[j] >= '0' && s[j] <= '9') ||
                      (s[j] >= 'a' && s[j] <= 'f') ||
                      (s[j] >= 'A' && s[j] <= 'F')))
                    return false;
                j++;
            }
            if (i == j)
                return false;
            if (j - i > 4)
                return false;
            if (part == 7 && j < s.length())
                return false;
            i = j + 1;
        }
        return true;
    }

public:
    string validIPAddress(string queryIP) {
        if (check4(queryIP))
            return "IPv4";
        if (check6(queryIP))
            return "IPv6";
        return "Neither";
    }
};