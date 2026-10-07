class Solution {
    int killemotions(vector<vector<int>>& books, int limit, int index , vector<int>&dp ) {
        if (index == books.size())
            return 0;
        int width = 0;
        int maxHeight = 0;
        int ans = INT_MAX;
        if(dp[index] != -1)
            return dp[index];
        for (int i = index; i < books.size(); i++) {
            width += books[i][0];
            if (width > limit)
                break;
            maxHeight = max(maxHeight, books[i][1]);
            ans = min(ans, maxHeight + killemotions(books, limit, i + 1 , dp));
        }
        return dp[index] = ans;
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<int>dp(books.size(),-1);
        return killemotions(books, shelfWidth, 0 , dp);
    }
};