class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = INT_MIN;
        int sold = 0;
        int rest = 0;
        for (int price : prices) {
            int prevHold = hold;
            int prevSold = sold;
            int prevRest = rest;
            hold = max(prevHold, prevRest - price);
            sold = prevHold + price;
            rest = max(prevRest, prevSold);
        }
        return max(sold, rest);
    }
};