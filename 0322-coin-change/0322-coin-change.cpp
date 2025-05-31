class Solution {
public:
    // int f(int i, vector<int> &coins, int amount){
    //     if(i < 0){
    //         return amount == 0 ? 0 : 1e9;
    //     }
        
    //     int skip = f(i-1, coins, amount);
    //     int take = coins[i] <= amount ? 1 + f(i, coins, amount - coins[i]) : 1e9;

    //     return min(skip, take);
    // }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // int ans = f(n-1, coins, amount);
        // return ans == 1e9 ? -1 : ans;

        vector<vector<int>> dp(n, vector<int> (amount+1, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j <= amount; j++){
                int skip = i-1 >= 0 ? dp[i-1][j] : j == 0 ? 0 : 1e9;
                int take = coins[i] <= j ? 1 + dp[i][j - coins[i]] : 1e9;

                dp[i][j] = min(skip, take);
                // cout << dp[i][j] << " " ;
            }
            // cout << endl;
        }

        return dp[n-1][amount] == 1e9 ? -1 : dp[n-1][amount];


    }
};