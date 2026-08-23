class Solution {
public:
    int numSub(string s) {
        long long count = 0;
        int MOD = 1000000007;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                int j = i;
                while (j < s.length() && s[j] == '1')
                    j++;
                long long n = j - i;
                count += n * (n + 1) / 2;
                i = j - 1;
            }
        }
        return count % MOD;
    }
};