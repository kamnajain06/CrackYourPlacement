class Solution {
public:
    int fun(int amount, vector<int> &coins, int n, vector<int> &dp){
        if(amount == 0) return 0;
        
        if(dp[amount] != -1) return dp[amount];

        int mini = 1e8;
        for(int i=0; i<n; i++){
            int pick = coins[i] <= amount ? 1 + fun(amount-coins[i], coins, n, dp) : 1e8;
            mini = min(mini, pick);
        }
        
        return dp[amount] = mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, -1);
        int res = fun(amount, coins, n, dp);
        return res == 1e8 ? -1 : res;
    }
};