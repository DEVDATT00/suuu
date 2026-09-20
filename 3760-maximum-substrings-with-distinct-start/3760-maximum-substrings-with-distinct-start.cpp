class Solution {
public:
    int maxDistinct(string s) {
        bool seen[26] = {false};

        for (char c : s) {
            seen[c - 'a'] = true;
        }

        int count = 0;

        for (int i = 0; i < 26; i++) {
            if (seen[i]) {
                count++;
            }
        }
        return count;
    }
};