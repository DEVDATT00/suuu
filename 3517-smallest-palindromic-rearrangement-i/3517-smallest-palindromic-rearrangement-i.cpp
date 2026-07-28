class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string half = "";
        char mid = '\0';

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2)
                mid = char(i + 'a');

            half.append(freq[i] / 2, char(i + 'a'));
        }

        string ans = half;

        if (mid != '\0')
            ans += mid;

        reverse(half.begin(), half.end());
        ans += half;

        return ans;
    }
};