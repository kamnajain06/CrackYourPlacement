class Solution {
public:
    // int fun(int i, vector<int>& prices, int n, int canBuy,
    //         vector<vector<int>>& dp) {
    //     if (i >= n)
    //         return 0;
    //     if (dp[i][canBuy] != -1)
    //         return dp[i][canBuy];
    //     if (canBuy) {
    //         return dp[i][canBuy] =
    //                    max(-prices[i] + fun(i + 1, prices, n, 0, dp),
    //                        fun(i + 1, prices, n, 1, dp));
    //     }
    //     return dp[i][canBuy] = max(prices[i] + fun(i + 2, prices, n, 1, dp),
    //                                fun(i + 1, prices, n, 0, dp));
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return fun(0, prices, n, 1, dp);

        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--) {
            dp[i][1] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
            if (i + 2 <= n)
                dp[i][0] = max(prices[i] + dp[i + 2][1], dp[i + 1][0]);
            else
                dp[i][0] = max(prices[i], dp[i + 1][0]);
        }

        return dp[0][1];
    }
};