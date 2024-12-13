class Solution {
public:
//     int fun(int ind, int amount, vector<int> &coins, int n, vector<vector<int>> &dp){
//         if(amount == 0) return 1;
//         if(ind >= n || amount < 0) return 0;

//         if(dp[ind][amount] != -1) return dp[ind][amount];

//         int pick = fun(ind, amount - coins[ind], coins, n, dp);
//         int skip = fun(ind+1, amount, coins, n, dp);

//         return dp[ind][amount] = pick + skip;
//     }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // // MEMOIZATION
        // vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        // return fun(0, amount, coins, n, dp);

        // TABULATION
        vector<vector<long long>> dp(n, vector<long long> (amount+1, 0));
        for(int row = 0; row<n; row++){
            dp[row][0] = 1;
        }
        for(int row=0; row<n; row++){
            for(int sum=1; sum<= amount; sum++){
                int pick = sum >= coins[row] ? dp[row][sum - coins[row]] : 0;
                int skip = (row > 0) ? dp[row-1][sum] : 0;
                dp[row][sum] = (long long) pick +  (long long)skip;
            }
        }
        return dp[n-1][amount];
    }
};