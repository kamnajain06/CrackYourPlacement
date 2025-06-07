class Solution {
public:
    int f(int i, int buy, vector<int> &prices, int n, vector<vector<int>> &dp){
        if(i >= n) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        int op1 = f(i+1, buy, prices, n, dp);
        if(buy){
            return dp[i][buy] = max(-prices[i] + f(i+1, buy-1, prices, n, dp) , op1);
        }
        return dp[i][buy] = max(prices[i] + f(i+2, buy + 1, prices, n, dp) , op1);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return f(0, 1, prices, n, dp);
    }
};