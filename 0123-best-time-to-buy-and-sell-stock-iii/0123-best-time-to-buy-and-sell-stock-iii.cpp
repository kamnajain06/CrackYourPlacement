class Solution {
public:
    // int fun(int i, vector<int>& prices, int n, int maxTrans, int canBuy) {
    //     if (i >= n || maxTrans <= 0)
    //         return 0;

    //     if (canBuy) {
    //         return max(-prices[i] + fun(i + 1, prices, n, maxTrans, 0),
    //                    fun(i + 1, prices, n, maxTrans, 1));
    //     }
    //     return max(prices[i] + fun(i + 1, prices, n, maxTrans - 1, 1),
    //                fun(i + 1, prices, n, maxTrans, 0));
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // return fun(0, prices, n, 2, 1);
        vector<vector<vector<int>>> dp(
            n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int i = n-1; i >= 0; i--) {
            for (int j = 0; j < 2; j++) {
                for (int k = 1; k < 3; k++) {
                    if (j == 0) {
                        dp[i][j][k] = max(prices[i] + dp[i + 1][1][k - 1],
                                              dp[i + 1][0][k]);
                    } else {
                        dp[i][j][k] =
                            max(-prices[i] + dp[i + 1][0][k], dp[i + 1][1][k]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};