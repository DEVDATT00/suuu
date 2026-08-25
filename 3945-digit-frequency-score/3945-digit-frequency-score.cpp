class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int>count(10,0);
        while(n > 0){
            count[n % 10]++;
            n /= 10;
        }
        int ans = 0;
        for(int i = 0 ; i < 10 ; i++){
            ans += count[i] * i;
        }
        return ans;
    }
};