class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    void name(string& s, int i, int j) {
        while (i < j) {
            swap(s[i++], s[j--]);
        }
    }

public:
    string reverseWords(string s) {
        int count = 0;
        int temcount = 0;
        int i = 0;
        while (i < s.length() && s[i] != ' ') {
            if (isVowel(s[i])) {
                count++;
            }
            i++;
        }
        int j = i + 1;
        while (j < s.length() && i < s.length()) {
            while (j < s.length() && s[j] != ' ') {
                if (isVowel(s[j])) {
                    temcount++;
                }
                j++;
            }
            if (temcount == count) {
                name(s, i+1, j-1);
            }
            temcount = 0;
            i = j;
            j = j + 1;
        }
        return s;
    }
};