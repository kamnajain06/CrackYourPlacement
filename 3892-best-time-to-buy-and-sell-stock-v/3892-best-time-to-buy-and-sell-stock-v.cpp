class Solution {
public:
    long long f(int i, int state, int n, vector<int>& prices, int k,
                vector<vector<vector<long long>>>& dp) {
        if (k <= 0)
            return 0;
        if (i >= n)
            return -1e9;
        if (dp[i][state][k] != -1)
            return dp[i][state][k];
        long long profit = 0;
        if (state == 0) {
            long long idle = f(i + 1, 0, n, prices, k, dp);
            long long buy = -prices[i] + f(i + 1, 2, n, prices, k, dp);
            long long sell = prices[i] + f(i + 1, 1, n, prices, k, dp);
            profit = max({idle, buy, sell});
        } else if (state == 1) {
            long long buy = -prices[i] + f(i + 1, 0, n, prices, k - 1, dp);
            long long notBuy = f(i + 1, 1, n, prices, k, dp);
            profit = max(buy, notBuy);
        } else {
            long long sell = prices[i] + f(i + 1, 0, n, prices, k - 1, dp);
            long long notSell = f(i + 1, 2, n, prices, k, dp);
            profit = max(sell, notSell);
        }
        return dp[i][state][k] = profit;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        // vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>
        // (3, vector<long long> (k+1, -1))); return f(0, 0, n, prices, k, dp);

        vector<vector<vector<long long>>> dp(
            n + 1, vector<vector<long long>>(3, vector<long long>(k+1, -1e9)));
        for (int i = n; i >= 0; i--) {
            for (int state = 0; state < 3; state++) {
                dp[i][state][0] = 0;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= k; j++) {
                for (int state = 0; state <= 2; state++) {
                    long long profit = 0;
                    if (state == 0) {
                        long long idle = dp[i + 1][0][j];
                        long long buy = -prices[i] + dp[i + 1][2][j];
                        long long sell = prices[i] + dp[i + 1][1][j];
                        profit = max({idle, buy, sell});
                    } else if (state == 1) {
                        long long buy = -prices[i] + dp[i + 1][0][j - 1];
                        long long notBuy = dp[i + 1][1][j];
                        profit = max(buy, notBuy);
                    } else {
                        long long sell = prices[i] + dp[i + 1][0][j - 1];
                        long long notSell = dp[i + 1][2][j];
                        profit = max(sell, notSell);
                    }
                    dp[i][state][j] = profit;
                }
            }
        }
        long long ans = 0;
        for(int j=0; j<=k; j++){
            ans = max(ans, dp[0][0][j]);
        }
        return ans;
    }
};