class Solution {
    vector<string> ans;

    void makethis(string s, int i, string navi) {
        if(i == s.length()) {
            ans.push_back(navi);
            return;
        }

        if(isdigit(s[i])) {
            makethis(s, i + 1, navi + s[i]);
        }
        else {
            makethis(s, i + 1, navi + (char)tolower(s[i]));
            makethis(s, i + 1, navi + (char)toupper(s[i]));
        }
    }

public:
    vector<string> letterCasePermutation(string s) {
        makethis(s, 0, "");
        return ans;
    }
};