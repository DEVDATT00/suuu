class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        for(int i = 0; i < stones.size(); i++) {
            stones[i] = stones[i] % 3;
        }

        sort(stones.begin(), stones.end());
        int zero = 0;
        int one = 0;
        int two = 0;

        for(int x : stones) {
            if(x == 0)
                zero++;
            else if(x == 1)
                one++;
            else
                two++;
        }

        if(zero % 2 == 0) {
            return one > 0 && two > 0;
        }
        else {
            return abs(one - two) > 2;
        }
    }
};