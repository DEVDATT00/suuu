class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string retunr = "";
        int countone = 0;
        int i = 0;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == '1')
                countone++;
            if (countone == k) {
                while (s[i] == '0')
                    i++;
                string curr = s.substr(i, j - i + 1);
                if (retunr == "" || curr.length() < retunr.length() || (curr.length() ==retunr.length() && curr < retunr)) {
                    retunr = curr;
                }
                countone--;
                i++;
            }
        }
        return retunr;
    }
};