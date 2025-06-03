class Solution {
public:
    // int f(int i, int n, int sum, int &amount, vector<int> &coins, vector<vector<int>> &dp){
    //     if(i >= n){
    //         if(sum == amount) return 1;
    //         return 0;
    //     }
    //     if(sum == amount) return 1;
    //     if(sum > amount) return 0;

    //     if(dp[i][sum] != -1) return dp[i][sum];

    //     int pick = f(i, n, sum + coins[i], amount, coins, dp);
    //     int skip = f(i+1, n, sum, amount, coins, dp);

    //     return dp[i][sum] = pick + skip;
    // }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        // return f(0, n, 0, amount, coins, dp);

        // vector<vector<int>> dp(n+1, vector<int> (amount+1, 0));
        // dp[n][amount] = 1;

        // for(int i=n-1; i>=0; i--){
        //     for(int j = amount; j>=0; j--){
        //         int pick = j + coins[i] <= amount ? dp[i][j + coins[i]] : 0;
        //         int skip = dp[i+1][j];

        //         dp[i][j] = pick + skip;
        //     }
        // }

        // return dp[0][0];


        vector<long long> dp(amount+1, 0);
        dp[amount] = 1;

        for(int i=n-1; i>=0; i--){
            vector<long long> curr(amount+1, 0);
            for(int j = amount; j>=0; j--){
                int pick = j + coins[i] <= amount ? curr[j + coins[i]] : 0;
                int skip = dp[j];

                curr[j] = (long long) pick +  (long long)skip;
            }
            dp = curr;
        }

        return dp[0];
    }
};