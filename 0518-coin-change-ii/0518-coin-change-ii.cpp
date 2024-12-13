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
        // vector<vector<long long>> dp(n, vector<long long> (amount+1, 0));
        vector<long long> dp(amount+1, 0);
        dp[0] = 1;
        
        for(int row=0; row<n; row++){
            vector<long long> temp(amount+1, 0);
            temp[0] = 1;
            for(int sum=1; sum<= amount; sum++){
                int pick = sum >= coins[row] ? temp[sum - coins[row]] : 0;
                int skip = (row > 0) ? dp[sum] : 0;
                temp[sum] = (long long) pick +  (long long)skip;
            }
            dp = temp;
        }
        return dp[amount];
    }
};