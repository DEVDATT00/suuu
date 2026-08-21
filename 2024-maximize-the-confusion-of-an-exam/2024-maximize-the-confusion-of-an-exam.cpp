class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i = 0;
        int n = answerKey.length();
        int mx = 0;
        int t = 0, f = 0;
        for (int j = 0; j < n; j++) {
            if (answerKey[j] == 'T')
                t++;
            else
                f++;
            while (t > k && f > k) {
                if (answerKey[i] == 'T')
                    t--;
                else
                    f--;

                i++;
            }
            mx = max(mx, j - i + 1);
        }
        return mx;
    }
};